#pragma once
#include "dshowcapture.hpp"
#include <atomic>
#include <condition_variable>
#include <list>
#include <memory>

class DeviceManager;

struct DShowProps
{
    std::string cameraId;
    std::string audioId;

    int height = 0;
    int width = 0;
    int volume = 100;
    bool flip = false;
    bool useCustomAudioDevice = false;
    DShow::AudioMode audioMode = DShow::AudioMode::Capture;
};

class DShowCore
{
  public:
    enum class Action
    {
        None,
        Activate,
        ActivateBlock,
        Deactivate,
        Shutdown,
        ConfigVideo,
        ConfigAudio,
        ConfigCrossbar1,
        ConfigCrossbar2,
    };

    DShowCore();
    ~DShowCore();
    // DShow::VideoConfig GetVideoConfig();
    // DShow::AudioConfig GetAudioConfig();
    // void SetVideoConfig(const DShow::VideoConfig &config);
    // void SetAudioConfig(const DShow::AudioConfig &config);

    void Init();
    void Run();
    void PushAction(const Action &action);
    void Restart();
    void Stop();

    DeviceManager *GetDeviceMgr()
    {
        return deviceMgr_.get();
    }

    void SetProps(const DShowProps &props);
    DShowProps& GetProps();
    void RefreshProps();

    DShow::VideoProc OnVideoCallback = nullptr;
    DShow::AudioProc OnAudioCallback = nullptr;

  private:
    void ThreadLoop();
    void OnActivate();
    void OnDeactivate();

    // 每帧采集回调
    void OnVideoData(const DShow::VideoConfig &config, unsigned char *data,
                     size_t size, long long startTime, long long endTime,
                     long rotation);

    void OnAudioData(const DShow::AudioConfig &config, unsigned char *data,
                     size_t size, long long startTime, long long endTime);

    // 事件回调
    void OnActionChanged(const Action &action);

    // Infos
    std::unique_ptr<DeviceManager> deviceMgr_;
    DShow::VideoDevice *curVideoDevInfo_;
    DShow::AudioDevice *curAudioDevInfo_;

    // Device
    DShow::Device device_;

    // Config
    DShow::VideoConfig videoConfig_;
    DShow::AudioConfig audioConfig_;
    DShowProps props_;

    //
    std::list<Action> actions_;
    std::mutex mutex_;
    std::condition_variable cond_;
    std::atomic_bool isRunning_ = false;
};

class DeviceManager
{
  public:
    void Init();

    const std::vector<DShow::VideoDevice> &GetVideoDeviceInfos();
    const std::vector<DShow::AudioDevice> &GetAudioDeviceInfos();

    const std::vector<const char *> &GetVideoDeviceIdsCStr();
    const std::vector<const char *> &GetAudioDeviceIdsCStr();

    const std::vector<std::string> &GetVideoDeviceIds();
    const std::vector<std::string> &GetAudioDeviceIds();

    DShow::VideoDevice *FindVideoDevice(const std::string id);
    DShow::AudioDevice *FindAudioDevice(const std::string id);

  private:
    std::vector<DShow::VideoDevice> videoDevInfos_;
    std::vector<DShow::AudioDevice> audioDevInfos_;

    std::vector<std::string> videoDevIds_;
    std::vector<std::string> audioDevIds_;

    std::vector<const char *> videoDevIdsCStr_;
    std::vector<const char *> audioDevIdsCStr_;
};

