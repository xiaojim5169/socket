#include "common.h"
#define IP "127.0.0.1"
int main(){
    int fd;
    struct sockaddr_in addr{};
    char buf[1024],password[10],rePassword[10];
    int i,n,choice;
    Msg msg;
    memset(&msg,0,sizeof(msg));
    bzero(&addr,sizeof(addr));
    fd=Socket(AF_INET,SOCK_STREAM,0);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9988);
    inet_pton(AF_INET,IP,&addr.sin_addr.s_addr);

    Connect(fd,(struct sockaddr *)&addr,sizeof(addr));
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
    while(1){
        printf("请输入文字：\n");
        scanf("%s",msg.data);
        printf("%s,%s,%s\n",msg.id,msg.password,msg.data);
        memset(buf,0,sizeof(buf));
        memcpy(buf,&msg,sizeof(msg));
        write(fd,buf,sizeof(buf));
        memset(buf,0,sizeof(buf));
        n=read(fd,buf,sizeof(buf));
        memset(&msg,0,sizeof(msg));
        memcpy(&msg,buf,sizeof(msg));
        printf("%s,%s,%s",msg.id,msg.password,msg.data);
    }

    close(fd);
    return 0;
}