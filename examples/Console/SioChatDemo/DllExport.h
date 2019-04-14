#pragma once

#include "socket_impl.h"

enum ERROR_CODE {
  ERROR_NONE,
  ERROR_ONE
};

#include <string>

#define DLLEXPORT __declspec(dllexport)

extern "C" {

  DLLEXPORT int TestString(const char* name);
  DLLEXPORT int CreateAndJoin();
}
