#include "common.h"
int main(){
    int lfd,cfd;                         //lfd用来监听，cfd是具体的客户套接字
    struct sockaddr_in serv_addr{},clie_addr{};
    socklen_t addrlen;
    int n,i;
    char buf[1024];
    char ip[1024];
    pid_t pid;
    //初始化结构体serv_addr
    bzero(&clie_addr,sizeof(clie_addr));
    lfd=Socket(AF_INET,SOCK_STREAM,0);
    serv_addr.sin_port=htons(9988);
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    addrlen=sizeof(clie_addr);

    Bind(lfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));

    listen(lfd,30);
    while(true){
        cfd=Accept(lfd,(struct sockaddr*)&clie_addr,&addrlen);
        printf("sadasdasd");
        printf("client ip = %s",inet_ntop(AF_INET,&clie_addr.sin_addr.s_addr,ip,sizeof(ip)));
        pid=fork();
        if(pid==0){            //子进程
            close(lfd);
            break;
        }
        else if(pid==-1){      //创建子进程失败的处理
            perror("fork error");
            exit(-1);
        }else{
            close(cfd);                //父进程关闭cfd
            signal(SIGCHLD,wait_child);//注册信号捕捉函数，回收子进程
        }
    }
    while(true){    //子进程任务
        n=read(cfd,buf,sizeof(buf));
        if(n==0){
            close(cfd);
            return 0;
        }else if(n<0){
            perror("read error");
            exit(-1);
        }else{
            write(STDOUT_FILENO,buf,n);
            for(i=0;i<n;i++){
                buf[i]=toupper(buf[i]);
            }
            write(cfd,buf,n);
        }
    }
}