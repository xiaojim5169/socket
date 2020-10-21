#include "common.h"
#define IP "127.0.0.1"
int main(){
    int fd;
    struct sockaddr_in addr{};
    char buf[1024];
    int n;

    bzero(&addr,sizeof(addr));
    fd=Socket(AF_INET,SOCK_STREAM,0);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9988);
    inet_pton(AF_INET,IP,&addr.sin_addr.s_addr);

    Connect(fd,(struct sockaddr *)&addr,sizeof(addr));
    printf("服务器连接成功！\n");
    while(1){
        fgets(buf,sizeof(buf),stdin);
        write(fd,buf,strlen(buf));
        n=read(fd,buf,sizeof(buf));
        write(STDOUT_FILENO,buf,n);
    }
    close(fd);
    return 0;
}