#pragma once
#include "../../src/sio_client.h"

#include <functional>
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <string>

using namespace sio;
using namespace std;

class ConnectionListener {

  sio::client &handler;

public:

  ConnectionListener(sio::client& h) :
    handler(h) {
  }
  void OnConnected();
  void OnClose(client::close_reason const& reason);
  void OnFail();
};

class PempSocket {

  sio::client socket;

public :
  PempSocket() {
  }

  void CreateSocket();
  void JoinServer(std::string address);
};
