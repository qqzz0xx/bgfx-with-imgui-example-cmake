#include "HRI.h"
#include "bgfx/bgfx.h"
#include "bx/math.h"
#include <array>
#include <vector>
#include <memory_resource>

using mat4 = std::array<float, 16>;
struct HRIContext;
static mat4 makeMat4();

struct HRIContext
{
  std::vector<mat4> modelMatrixs;
  std::vector<mat4> viewMatrixs;
  std::vector<mat4> projectMatrixs;

  HRIContext() {
    modelMatrixs.push_back(makeMat4());
    viewMatrixs.push_back(makeMat4());
    projectMatrixs.push_back(makeMat4());
  }
};

static HRIContext s_ctx;

static mat4 makeMat4() {
  mat4 res = {
    1,0,0,0,
    0,1,0,0,
    0,0,1,0,
    0,0,0,1 };

  return res;
}

void HRI::push_viewTarget(uint16_t viewId) {
  

}

void HRI::pop_viewTarget() {

}

void HRI::push_matrix()
{
  s_ctx.modelMatrixs.push_back(makeMat4());
}

void HRI::pop_matrix()
{
  s_ctx.modelMatrixs.pop_back();
}

void HRI::setMatrix(float m[16])
{
  auto& cur = s_ctx.modelMatrixs.back();
  memcpy(cur.data(), m, 16 * sizeof(float));
}

void HRI::push_viewMatrix()
{
  s_ctx.viewMatrixs.push_back(makeMat4());
}

void HRI::pop_viewMatrix()
{
  s_ctx.viewMatrixs.pop_back();
}

void HRI::push_projectMatrix()
{
  s_ctx.projectMatrixs.push_back(makeMat4());
}

void HRI::pop_projectMatrix()
{
  s_ctx.projectMatrixs.pop_back();
}

void HRI::ortho(float _left, float _right, float _bottom, float _top, float _near, float _far, float _offset)
{
  auto& cur = s_ctx.projectMatrixs.back();
  auto caps = bgfx::getCaps();
  bx::mtxOrtho(cur.data(), _left, _right, _bottom, _top, _near, _far, _offset, caps->homogeneousDepth);
}

void HRI::perspective(float _fovy, float _aspect, float _near, float _far)
{
  auto& cur = s_ctx.projectMatrixs.back();
  auto caps = bgfx::getCaps();
  bx::mtxProj(cur.data(), _fovy, _aspect, _near, _far, caps->homogeneousDepth);
}

void HRI::push_MVP()
{
  push_matrix();
  push_viewMatrix();
  push_projectMatrix();
}

void HRI::updateMVP(uint16_t viewId)
{
  const auto& curModel = s_ctx.modelMatrixs.back();
  const auto& curView = s_ctx.viewMatrixs.back();
  const auto& curProj = s_ctx.projectMatrixs.back();

  bgfx::setTransform(curModel.data());
  bgfx::setViewTransform(viewId, curView.data(), curProj.data());
}

void HRI::pop_MVP()
{
  pop_matrix();
  pop_viewMatrix();
  pop_projectMatrix();
}

void HRI::draw_rect(float x, float y, int w, int h)
{
}




