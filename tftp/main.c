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
    struct addrinfo hints;
    struct addrinfo *res;
    char bufferServerName[128]={0};
    char bufferHostName[128]={0};
    
    memset(&hints,0,sizeof(struct addrinfo));
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_family = AF_INET;
    printf("GetAddInfo on : %s\n", argv[1]);
    getaddrinfo(argv[1], argv[2],&hints,&res);
    struct addrinfo *current;
    current = res;
    while(current!=NULL){
    printf("Found one answer : \t ai-family = %s \t ai-socktype = %s \t ai-protocol = %s\n",
    (current->ai_family)==2?"AF_INET":"AF_INET6", socketTypeString[current->ai_socktype],
    current->ai_protocol==6?"IPPROTO_TCP":(current->ai_protocol==17?"IPPROTO_UDP":"IPPROTO_IP"));

    int status = getnameinfo(current->ai_addr,current->ai_addrlen,bufferHostName,128,
    bufferServerName,128,NI_NUMERICHOST | NI_NUMERICSERV);
    if (status!=0) printf("status :%s\n", gai_strerror(status));
    printf("Host: %s \t Service: %s\n", bufferHostName, bufferServerName);
    current=current->ai_next;
    }            
}