#include "common.h"
int main(){
    int listenfd,connfd,epfd,sockfd;                //lfd用来监听，cfd是具体的客户套接字,epfd接收一个epoll句柄
    struct sockaddr_in serv_addr{},clie_addr{};
    socklen_t addrlen;
    int opt = 1;
    int n,i,nReady;
    int num=0;
    char buf[1024];
    char str[1024];
//    pid_t pid;
    struct epoll_event tep{},ep[SIZE];
    Msg msg;

    epfd =Epoll_create(SIZE);      //创建epoll句柄，并设定建议监听值SIZE

    listenfd=Socket(AF_INET,SOCK_STREAM,0);
    Setsockopt(listenfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));  //设置端口复用

    //初始化结构体serv_addr
    bzero(&serv_addr,sizeof(serv_addr));
    serv_addr.sin_port=htons(SERV_PORT);
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);


    Bind(listenfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
    listen(listenfd,SIZE);
    tep.events = EPOLLIN;
    tep.data.fd = listenfd;
    Epoll_ctl(epfd,EPOLL_CTL_ADD,listenfd,&tep);
    while(true){
        nReady = Epoll_wait(epfd,ep,SIZE,10);
        for(i=0;i<nReady;i++){
            if(!(ep[i].events&EPOLLIN)){
                continue;
            }
            if(ep[i].data.fd==listenfd){
                bzero(&clie_addr,sizeof(clie_addr));
                addrlen=sizeof(clie_addr);
                connfd=Accept(listenfd,(struct sockaddr*)&clie_addr,&addrlen);
                printf("Received from %s at %d\n",inet_ntop(AF_INET,&clie_addr.sin_addr,str,sizeof(str)),ntohs(clie_addr.sin_port));
                printf("cfd %d---client %d\n",connfd,++num);
                tep.events = EPOLLIN;
                tep.data.fd = connfd;
                Epoll_ctl(epfd,EPOLL_CTL_ADD,connfd,&tep);
            }
            else{
                sockfd = ep[i].data.fd;
                memset(buf,0,sizeof(buf));
                n = read(sockfd,buf,sizeof(buf));
                if(n==0){
                    Epoll_ctl(epfd,EPOLL_CTL_DEL,sockfd, nullptr);
                    Close(sockfd);
                    printf("client[%d] closed connection\n",sockfd);
                }else if(n<0){
                    perror("read n <0 error");
                    Epoll_ctl(epfd,EPOLL_CTL_DEL,sockfd, nullptr);
                    Close(sockfd);
                }else{
                    memset(&msg,0,sizeof(msg));
                    memcpy(&msg,buf,sizeof(msg));
                    printf("%s,%s,%s\n",msg.id,msg.password,msg.data);
                    write(sockfd,buf,sizeof(buf));
                }
            }
        }
    }
    Close(listenfd);
    return 0;
}