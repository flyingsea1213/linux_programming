#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int
main(int argc, char **argv)
{

    int sock_fd;
    int dmn, type, prot;

    struct sockaddr_in serv_addr;
    char p[40] = {0};
    char *ip = p;

    dmn = AF_INET;
    type = SOCK_STREAM;
    prot = IPPROTO_IP; 

    if ((sock_fd = socket(dmn, type, prot)) == -1)
        perror("open socket error");
    
    memset(&serv_addr, 0x00, sizeof(struct sockaddr_in));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(1025); // should cannot be less than 1024 unless the process has the appropriate privilege.
    if (gets(p) != NULL)
        serv_addr.sin_addr = inet_addr(ip);

    if (0 != bind(sock_fd, (struct *sockaddr_in)&serv_addr, sizeof(serv_addr) ))
        perror("bind error");
    
    /* listen */
    if (0 != listen(serv_sock, 20))
        perror("enter listen status error");






}



