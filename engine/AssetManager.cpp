#include "AssetManager.h"
using namespace sse;

using ByteBuffer = std::string;

std::unordered_map<std::string, std::shared_ptr<Mesh>> s_meshes;
std::unordered_map<std::string, std::shared_ptr<ByteBuffer>> s_shaders;




struct Plane : public Mesh {
  Plane() {
    vertexs = {
        {{-1.0f, 0.0f, 1.0f}, {0.0f, 1.0f, 0.0f}, {1.0f, 1.0f}},
        {{1.0f, 0.0f, 1.0f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f}},
        {{-1.0f, 0.0f, -1.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 1.0f}},
        {{1.0f, 0.0f, -1.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}},
    };

    indexs = {
        0, 1, 2, 1, 3, 2,
    };
  }
};

void AssetManager::LoadDefault() {
  s_meshes.emplace("@plane", std::make_shared<Plane>());
}

bool AssetManager::LoadMesh(const std::string& url) { return false; }

Mesh* AssetManager::FindMesh(const std::string& url) {
  auto it = s_meshes.find(url);
  if (it == s_meshes.end()) return nullptr;

  return s_meshes[url].get();
}

ByteBuffer* AssetManager::FindShader(const std::string& url) {
  auto it = s_shaders.find(url);
  if (it == s_shaders.end()) return nullptr;

  return s_shaders[url].get();
}
