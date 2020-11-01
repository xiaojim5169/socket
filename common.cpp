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

Msg clLogin(){    //客户端登陆函数
    int choice,i;
    char password[10],rePassword[10];
    Msg msg;
    memset(password,0,sizeof(password));
    memset(rePassword,0,sizeof(rePassword));
    memset(&msg,0,sizeof(msg));

    printf("服务器连接成功！\n");
    printf("是否拥有账号？(Y/n)\nY:登录\t n:注册\n");
    choice = getc(stdin);
    getchar();
    if(choice=='Y'||choice=='y'){
        printf("请输入用户id(10个数字)：\n");
        while(true){
            fgets(msg.id,sizeof(msg.id),stdin);
            for(i=0;i<10;i++){
                if(msg.id[i]<'0'||msg.id[i]>'9'){
                    if(msg.id[i]=='\n'){
                        printf("输入不足10个数字\n");
                        break;
                    }
                    printf("输入的用户id中有些不是数字！请再次输入！\n");
                    break;
                }
            }
            if(i==10){
                break;
            }
        }
        printf("id输入成功！\n");
        getchar();
        printf("请输入密码：\n");
        fgets(password,sizeof(password),stdin);
        for(i=0;i<strlen(password)-1;i++){
            msg.password[i]=password[i];
        }
    }else{
        printf("请输入用户id(10个数字)：\n");
        while(true){
            fgets(msg.id,sizeof(msg.id),stdin);
            for(i=0;i<10;i++){
                if(msg.id[i]<'0'||msg.id[i]>'9'){
                    if(msg.id[i]=='\n'){
                        printf("输入不足10个数字\n");
                        break;
                    }
                    printf("输入的用户id中有些不是数字！请再次输入！\n");
                    break;
                }
            }
            if(i==10){
                break;
            }
        }
        printf("id输入成功！\n");
        getchar();
        while(true){
            printf("请输入密码：\n");
            fgets(password,sizeof(password),stdin);
            printf("请再次输入：\n");
            fgets(rePassword,sizeof(rePassword),stdin);
            if(!strcmp(password,rePassword)){
                printf("输入成功！\n");
                for(i=0;i<strlen(password)-1;i++){
                    msg.password[i]=password[i];
                }
                break;
            }
        }
    }
    return msg;
}
