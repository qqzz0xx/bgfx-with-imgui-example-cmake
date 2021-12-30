#pragma once
#include <cstdint>

namespace HRI
{
  void push_viewTarget(uint16_t viewId);
  void pop_viewTarget();

  void push_matrix();
  void pop_matrix();

  void setMatrix(float m[16]);

  void push_viewMatrix();
  void pop_viewMatrix();

  void push_projectMatrix();
  void pop_projectMatrix();

  void ortho(float _left, float _right, float _bottom, float _top, float _near, float _far, float _offset);
  void perspective(float _fovy, float _aspect, float _near, float _far);

  
  void push_MVP();
  void updateMVP(uint16_t viewId);
  void pop_MVP();

  void draw_rect(float x, float y, int w, int h);

};

