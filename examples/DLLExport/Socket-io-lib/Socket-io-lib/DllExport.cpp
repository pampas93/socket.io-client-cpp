// Created by Abhijit Srikanth (2019)

#include "DllExport.h"

DLLEXPORT int TestString(const char* name) {
  if (strcmp(name, "abhijit") == 0) {
    return 0;
  }
  else
    return 1;
}

DLLEXPORT int CreateAndJoin()
{
  PempSocket* socket = new PempSocket();
  socket->CreateSocket();
  socket->JoinServer("http://localhost:8090");
  return 0;
}