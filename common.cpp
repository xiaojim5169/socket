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
    int ret=accept(sockfd,addr,addrlen);
    if(ret==-1){
        perror("accept error");
        exit(-1);
    }
    return ret;
}
void Connect(int sockfd, const struct sockaddr *addr,socklen_t addrlen){
    if(connect(sockfd,addr,addrlen)==-1){
        perror("accept error");
        exit(-1);
    }
}
void wait_child(int signal){
    while(waitpid(0, nullptr,WNOHANG));
    printf("waitpid2");
}
