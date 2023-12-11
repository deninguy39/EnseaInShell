#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <memory.h>
#include <netdb.h>
#include <sys/socket.h>

#define request "GET / HTTP/1.1\r\nHost: %s\r\n\r\n"

const char * socketTypeString[7]={"","SOCK_STREAM", "SOCK_DGRAM"};

int main(int argc, char ** argv){
    char bufferServiceName[128]={0};
    char bufferHostName[128]={0};
    printf("***** Best TFTP Client ever ! *****\n");
    if (argc !=4){
    perror("Wrong usage : gettftp filename serveur port\n");
    exit(EXIT_SUCCESS);
    }

    printf("Trying to get %s from %s on port %s\n", argv[1],argv[2],argv[3]);

    struct addrinfo hints;
    struct addrinfo *res;
    memset(&hints,0,sizeof(struct addrinfo));
    hints.ai_protocol = IPPROTO_UDP;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_family = AF_INET;
    getaddrinfo(argv[2], argv[3],&hints,&res);
    getnameinfo(res->ai_addr, res->ai_addrlen, bufferHostName, 128,
    bufferServiceName, 128, NI_NUMERICHOST | NI_NUMERICSERV);
    printf("Serveur %s is solved as : %s:%s\n", argv[2], bufferHostName, bufferServiceName);
    char rrq[128]={0};
    sprintf(rrq+1, "\1%s netascii", argv[1]);
    rrq[strlen(argv[1])+2]=0;
    return 0;            
}
