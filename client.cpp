#include "common.h"
#define IP "127.0.0.1"
int main(){
    int fd;
    struct sockaddr_in addr{};
    char buf[1024];
    int n;
    Msg msg;
    memset(&msg,0,sizeof(msg));
    bzero(&addr,sizeof(addr));
    fd=Socket(AF_INET,SOCK_STREAM,0);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9988);
    inet_pton(AF_INET,CLIE_ADDR,&addr.sin_addr.s_addr);

    Connect(fd,(struct sockaddr *)&addr,sizeof(addr));
    msg=clLogin();
    while(true){
        printf("请输入文字：\n");
        scanf("%s",msg.data);
        memset(buf,0,sizeof(buf));
        memcpy(buf,&msg,sizeof(msg));
        write(fd,buf,sizeof(buf));
        memset(buf,0,sizeof(buf));
        n=read(fd,buf,sizeof(buf));
        if(n<0){
            perror("read error");
            exit(-1);
        }else if(n==0){
            break;   //跳出循环，关闭连接
        }
        memset(&msg,0,sizeof(msg));
        memcpy(&msg,buf,sizeof(msg));
        printf("%s,%s,%s\n",msg.id,msg.password,msg.data);
    }

    close(fd);
    return 0;
}