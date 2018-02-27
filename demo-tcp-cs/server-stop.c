#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h> 

#define BUF_SIZE 100

int main()
{
    //创建套接字
    int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    int optval=1;
    setsockopt(serv_sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &optval,sizeof (optval));
    //将套接字和IP、端口绑定
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
    serv_addr.sin_family = AF_INET;  //使用IPv4地址
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  //具体的IP地址
    serv_addr.sin_port = htons(7891);  //端口

    bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    //进入监听状态，等待用户发起请求
    listen(serv_sock, 20);
    char buffer[BUF_SIZE];
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size = sizeof(clnt_addr);

//  int clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
    int clnt_sock;

    while(1)
    {
        clnt_sock= accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
        while(1){
            read(clnt_sock, buffer, BUF_SIZE);
            if(buffer[0]=='\0' || strcmp(buffer,"exit")==0)
                break;

             if ((buffer[3] == 'c')||(buffer[3] == 'C')){
                printf("branch2: Trigger crash\n");
                int *a=NULL;
                *a = 11111;//a crash point
                break;
            }
            printf("rev meg: %s\n", buffer);
            memset(buffer,0,BUF_SIZE);
            return 0;
        }
        close(clnt_sock);
    }
    close(serv_sock);
    return 0;
}
