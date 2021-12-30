#pragma once

namespace sse {

struct SystemBase {
  virtual void init() = 0;
  virtual int shutdown() = 0;
  virtual bool update() = 0;

};

}  // namespace sse
