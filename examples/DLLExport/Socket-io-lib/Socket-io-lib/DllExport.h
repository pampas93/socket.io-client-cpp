#pragma once

// Created by Abhijit Srikanth (2019)

#include "SocketImpl.h"

#include <string>

#define DLLEXPORT __declspec(dllexport)

extern "C" {

  DLLEXPORT int CreateAndJoin();
}
