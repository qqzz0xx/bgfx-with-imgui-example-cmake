#pragma once

#include <memory>
#pragma once
#include "pch.h"
//
#include <string>
#include <unordered_map>
#include <vector>

#include "Mesh.h"

namespace sse {
namespace AssetManager {

void LoadDefault();
bool LoadMesh(const std::string& url);

Mesh* FindMesh(const std::string& url);
ByteBuffer* FindShader(const std::string& url);

};  // namespace MeshManager
}  // namespace sse
