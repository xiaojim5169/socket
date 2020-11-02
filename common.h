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
#include <sys/epoll.h>
#include <cerrno>
//用cat /proc/sys/fs/file-max 得到wsl的最大可建立的套接字数目为1048576
#define SIZE 100
#define SERV_PORT 9988
#define SERV_ADDR "10.0.8.13"
#define CLIE_ADDR "152.136.119.166"
typedef struct message{
    char id[11];
    char password[13];
    char data[1000];
}Msg;

int Socket(int domain, int type, int protocol);
void Bind(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
void Connect(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
void Close(int fd);
//void wait_child(int signal);
int Epoll_create(int size);
void Epoll_ctl(int epfd,int op,int fd,struct epoll_event *event);
int Epoll_wait(int epfd,struct epoll_event *events,int maxevents, int timeout);
void Setsockopt(int sockfd,int level,int optname,const void *optval,socklen_t optlen);
Msg clLogin();//客户端登陆函数
#endif //SOCKET_COMMON_H
