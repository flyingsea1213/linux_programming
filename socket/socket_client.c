#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <arpa/inet.h>
#include <sys/socket.h>

int
main(int argc, char **argv)
{
    int sock_client;
    struct sockaddr_in serv_addr;

    char p[10] = {0};
    char *ip = p;

    char rx_buf[40] = {0}; 

    memset(&serv_addr, 0, sizeof(struct sockaddr_in));
    sock_client = socket(AF_INET, SOCK_STREAM, 0);
    
    serv_addr.sin_family = AF_INET;
    printf("please input ip address\n");
    if ((gets(ip)) != NULL)
        serv_addr.sin_addr.s_addr = inet_addr(ip);
    serv_addr.sin_port = htons(1025);
    connect(sock_client, (struct sockaddr_in*)&serv_addr, sizeof(struct sockaddr_in));

    read(sock_client, rx_buf, sizeof(rx_buf)-1);

    printf("Message from server: %s\n", rx_buf);

    close(sock_client);
    
    return 0;
}
