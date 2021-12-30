#include "DShowCore.h"
#include "source/log.hpp"
#include <iostream>
#include <objbase.h>
#include <thread>

using namespace DShow;

DShowCore::DShowCore()
{
  deviceMgr_ = std::make_unique<DeviceManager>();

  videoConfig_.callback = [&](const VideoConfig& config, unsigned char* data,
    size_t size, long long startTime,
    long long stopTime, long rotation) {
      OnVideoData(config, data, size, startTime, stopTime, rotation);
  };

  audioConfig_.callback = [&](const AudioConfig& config, unsigned char* data,
    size_t size, long long startTime,
    long long stopTime) {
      OnAudioData(config, data, size, startTime, stopTime);
  };
}

DShowCore::~DShowCore()
{
}

// VideoConfig DShowCore::GetVideoConfig()
// {
//     return videoConfig_;
// }

// AudioConfig DShowCore::GetAudioConfig()
// {
//     return audioConfig_;
// }

// void DShowCore::SetVideoConfig(const DShow::VideoConfig &config)
// {
//     videoConfig_ = config;
// }

// void DShowCore::SetAudioConfig(const DShow::AudioConfig &config)
// {
//     audioConfig_ = config;
// }

void DShowCore::Init()
{
  deviceMgr_->Init();
}

void DShowCore::Run()
{
  isRunning_ = true;
  std::thread t([&] { ThreadLoop(); });
  t.detach();

  // std::unique_lock<std::mutex> lock(mutex_);
  // cond_.notify_all();
  // t.join();
}

void DShowCore::PushAction(const Action& action)
{
  std::unique_lock<std::mutex> lock(mutex_);
  actions_.push_back(action);
  cond_.notify_one();
}

void DShowCore::Restart()
{
  Stop();
  Run();
  OnActivate();
}

void DShowCore::Stop()
{
  std::unique_lock<std::mutex> lock(mutex_);
  isRunning_ = false;
  actions_.clear();
  cond_.notify_one();
}

void DShowCore::SetProps(const DShowProps& props)
{
  props_ = props;
}

DShowProps& DShowCore::GetProps()
{
  return props_;
}

void DShowCore::RefreshProps()
{
  curVideoDevInfo_ = deviceMgr_->FindVideoDevice(props_.cameraId);
  if (curVideoDevInfo_ == nullptr)
    return;

  videoConfig_.cx = props_.width;
  videoConfig_.cy_abs = props_.height;
  videoConfig_.cy_flip = props_.flip;
  videoConfig_.name = curVideoDevInfo_->name;
  videoConfig_.path = curVideoDevInfo_->path;

  curAudioDevInfo_ = deviceMgr_->FindAudioDevice(props_.audioId);
  if (!curAudioDevInfo_)
    return;

  audioConfig_.name = curAudioDevInfo_->name;
  audioConfig_.path = curAudioDevInfo_->path;

  audioConfig_.useVideoDevice =
    !props_.useCustomAudioDevice && !curVideoDevInfo_->separateAudioFilter;
  audioConfig_.useSeparateAudioFilter = curVideoDevInfo_->separateAudioFilter;
  audioConfig_.mode = props_.audioMode;
}

void DShowCore::ThreadLoop()
{
  CoInitialize(nullptr);
  while (isRunning_)
  {
    Action action = Action::None;
    {
      std::unique_lock<std::mutex> lock(mutex_);
      cond_.wait(lock, [&] { return !actions_.empty(); });

      action = actions_.front();
      actions_.pop_front();
    }

    OnActionChanged(action);
  }

  CoUninitialize();
}

void DShowCore::OnActivate()
{
  if (!device_.ResetGraph())
  {
    std::cout << "error: OnActivate::ResetGraph " << std::endl;
    return;
  }

  if (!device_.SetVideoConfig(&videoConfig_))
  {
    std::cout << "error: OnActivate::SetVideoConfig " << std::endl;
  }

  if (!device_.SetAudioConfig(&audioConfig_))
  {
    std::cout << "error: OnActivate::SetAudioConfig " << std::endl;
  }

  if (!device_.ConnectFilters())
  {
    std::cout << "error: OnActivate::ConnectFilters " << std::endl;
  }

  if (device_.Start() != Result::Success)
  {
    std::cout << "error: OnActivate::Start " << std::endl;
  }

  std::cout << "ok: OnActivate " << std::endl;
}

void DShowCore::OnDeactivate()
{
  device_.ShutdownGraph();

  std::cout << "ok: DShowCore::OnDeactivate " << std::endl;
}

void DShowCore::OnVideoData(const VideoConfig& config, unsigned char* data,
  size_t size, long long startTime, long long endTime,
  long rotation)
{
  std::cout << "ok: DShowCore::OnVideoData " << std::endl;

  if (OnVideoCallback)
  {
    OnVideoCallback(config, data, size, startTime, endTime, rotation);
  }
}

void DShowCore::OnAudioData(const DShow::AudioConfig& config,
  unsigned char* data, size_t size,
  long long startTime, long long endTime)
{
  std::cout << "ok: DShowCore::OnAudioData " << std::endl;

  if (OnAudioCallback)
  {
    OnAudioCallback(config, data, size, startTime, endTime);
  }
}

void DShowCore::OnActionChanged(const Action& action)
{
  switch (action)
  {
  case Action::Shutdown:
    OnDeactivate();
    isRunning_ = false;
    break;
  case Action::Deactivate:
    OnDeactivate();
    break;
  case Action::Activate:
    OnActivate();
    break;

  default:
    break;
  }

  std::cout << "DShowCore::OnActionChanged :" << (int)action << std::endl;
  // Debug(L"DShowCore::OnActionChanged : %d", (int)action);
}

void DeviceManager::Init()
{
  Device::EnumAudioDevices(audioDevInfos_);
  Device::EnumVideoDevices(videoDevInfos_);

  audioDevIds_.clear();
  videoDevIds_.clear();

  for (auto&& d : audioDevInfos_)
  {
    audioDevIds_.emplace_back(std::string(d.name.begin(), d.name.end()));
  }

  for (auto&& d : videoDevInfos_)
  {
    videoDevIds_.emplace_back(std::string(d.name.begin(), d.name.end()));
  }

  for (auto&& id : audioDevIds_)
  {
    audioDevIdsCStr_.emplace_back(id.c_str());
  }

  for (auto&& id : videoDevIds_)
  {
    videoDevIdsCStr_.emplace_back(id.c_str());
  }
}

const std::vector<DShow::VideoDevice>& DeviceManager::GetVideoDeviceInfos()
{
  return videoDevInfos_;
}

const std::vector<DShow::AudioDevice>& DeviceManager::GetAudioDeviceInfos()
{
  return audioDevInfos_;
}

DShow::VideoDevice* DeviceManager::FindVideoDevice(const std::string id)
{
  for (auto&& d : videoDevInfos_)
  {
    std::string str(d.name.begin(), d.name.end());
    if (str == id)
    {
      return &d;
    }
  }

  return nullptr;
}

DShow::AudioDevice* DeviceManager::FindAudioDevice(const std::string id)
{
  for (auto&& d : audioDevInfos_)
  {
    std::string str(d.name.begin(), d.name.end());
    if (str == id)
    {
      return &d;
    }
  }

  return nullptr;
}

const std::vector<const char*>& DeviceManager::GetVideoDeviceIdsCStr()
{
  return videoDevIdsCStr_;
}

const std::vector<const char*>& DeviceManager::GetAudioDeviceIdsCStr()
{
  return audioDevIdsCStr_;
}

const std::vector<std::string>& DeviceManager::GetVideoDeviceIds()
{
  return videoDevIds_;
}

const std::vector<std::string>& DeviceManager::GetAudioDeviceIds()
{
  return audioDevIds_;
}
