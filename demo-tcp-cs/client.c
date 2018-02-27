#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 100

int main(){
    //创建套接字

    //向服务器（特定的IP和端口）发起请求
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
    serv_addr.sin_family = AF_INET;  //使用IPv4地址
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  //具体的IP地址
    serv_addr.sin_port = htons(7891);  //端口

    char bufSend[BUF_SIZE];
    char bufRev[BUF_SIZE];
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    while(1){

    	printf("input a msg >");
     	scanf("%s", bufSend);
        write(sock, bufSend, BUF_SIZE); 
        memset(bufSend,0,BUF_SIZE);

        read(sock, bufRev, BUF_SIZE);
        printf("recv: %s", bufRev);
     }

    return 0;
}
