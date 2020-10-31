#include "common.h"
int Socket(int domain, int type, int protocol){
    int fd=socket(domain,type,protocol);
    if(fd==-1){
        perror("socket error");
        exit(-1);
    }
    return fd;
}
void Bind(int sockfd, const struct sockaddr *addr,socklen_t addrlen){
    if(bind(sockfd,addr,addrlen)==-1){
        perror("bind error");
        exit(-1);
    }
}
int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen){
    int ret;
    while(true){
        ret = accept(sockfd,addr,addrlen);
        if(ret<0){
            if((errno = ECONNABORTED)||(errno = EINTR)){
                continue;
            }else{
                perror("accept error");
                exit(-1);
            }
        }
        break;
    }
    return ret;
}
void Connect(int sockfd, const struct sockaddr *addr,socklen_t addrlen){
    if(connect(sockfd,addr,addrlen)==-1){
        perror("accept error");
        exit(-1);
    }
}
void Close(int fd){
    if(close(fd)==-1){
        perror("accept error");
        exit(-1);
    }
}
//void wait_child(int signal){
//    while(waitpid(0, nullptr,WNOHANG));
//    printf("waitpid2");
//}

int Epoll_create(int size){
    int ret = epoll_create(size);
    if(ret==-1){
        perror("epoll_create error");
        exit(-1);
    }
    return ret;
}

void Epoll_ctl(int epfd,int op,int fd,struct epoll_event *event){
    int ret = epoll_ctl(epfd,op,fd,event);
    if(ret==-1){
        perror("epoll_ctl error");
        exit(-1);
    }
}
int Epoll_wait(int epfd, struct epoll_event *events,int maxevents, int timeout){
    int ret =epoll_wait(epfd,events,maxevents,timeout);
    if(ret==-1){
        perror("epoll_wait error");
        exit(-1);
    }
    return ret;
}
void Setsockopt(int sockfd, int level,int optname,const void *optval, socklen_t optlen){
    if(setsockopt(sockfd,level,optname,optval,optlen)==-1){
        perror("setsockopt error");
        exit(-1);
    }
}
