//
// Created by Me on 2020/10/21.
//

#ifndef SOCKET_COMMON_H
#define SOCKET_COMMON_H
#include <cstdio>
#include <cstdlib>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>
#include <cctype>
#include <sys/wait.h>
int Socket(int domain, int type, int protocol);
void Bind(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
void Connect(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
void wait_child(int signal);

#endif //SOCKET_COMMON_H
