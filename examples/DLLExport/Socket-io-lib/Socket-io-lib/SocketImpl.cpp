// Created by Abhijit Srikanth (2019)

#include "SocketImpl.h"

std::mutex _lock;

std::condition_variable_any _cond;
bool connect_finish = false;

void ConnectionListener::OnConnected() {
  _lock.lock();
  _cond.notify_all();
  connect_finish = true;
  _lock.unlock();
}

void ConnectionListener::OnClose(client::close_reason const& reason) {
  std::cout << "sio closed " << std::endl;
}

void ConnectionListener::OnFail() {
  std::cout << "sio failed" << std::endl;
}

int participants = -1;
socket::ptr current_socket;

void bind_events()
{
  current_socket->on("new message", sio::socket::event_listener_aux([&](string const& name, message::ptr const& data, bool isAck, message::list &ack_resp)
  {
    _lock.lock();
    string user = data->get_map()["username"]->get_string();
    string message = data->get_map()["message"]->get_string();
    _lock.unlock();
  }));

  current_socket->on("user joined", sio::socket::event_listener_aux([&](string const& name, message::ptr const& data, bool isAck, message::list &ack_resp)
  {
    _lock.lock();
    string user = data->get_map()["username"]->get_string();
    participants = data->get_map()["numUsers"]->get_int();
    bool plural = participants != 1;

    _lock.unlock();
  }));
  current_socket->on("user left", sio::socket::event_listener_aux([&](string const& name, message::ptr const& data, bool isAck, message::list &ack_resp)
  {
    _lock.lock();
    string user = data->get_map()["username"]->get_string();
    participants = data->get_map()["numUsers"]->get_int();
    bool plural = participants != 1;
    _lock.unlock();
  }));
}

void PempSocket::CreateSocket() {

  ConnectionListener l(socket);

  socket.set_open_listener(std::bind(&ConnectionListener::OnConnected, &l));
  socket.set_close_listener(std::bind(&ConnectionListener::OnClose, &l, std::placeholders::_1));
  socket.set_fail_listener(std::bind(&ConnectionListener::OnFail, &l));
}

void PempSocket::JoinServer(std::string address) {

  socket.connect(address);
  _lock.lock();
  if (!connect_finish)
  {
    _cond.wait(_lock);
  }
  _lock.unlock();

}