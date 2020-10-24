cmake_minimum_required(VERSION 3.17)
project(socket)

set(CMAKE_CXX_STANDARD 11)

add_executable(server server.cpp common.cpp common.h)
add_executable(client client.cpp common.cpp common.h)
add_executable(client1 client.cpp common.cpp common.h)
add_executable(client2 client.cpp common.cpp common.h)
add_executable(client3 client.cpp common.cpp common.h)
add_executable(client4 client.cpp common.cpp common.h)