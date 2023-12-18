#include <stdlib.h>
#include <unistd.h>
#include <memory.h>
#include <netdb.h>
#include <sys/socket.h> 
#include <string.h>

int main(int argc, char ** argv){


    //validation of input arguments
	if (argc !=4){
		printf("Wrong usage \nPlease use %s hostname port file",argv[0]);
		exit(EXIT_FAILURE);
	}
	printf("Welcome to an implementation of a tftp client\n");

    //initialisation of the struct addrinfo  (it is where the address of the server will be stored)
	struct addrinfo hints;
	struct addrinfo * result;
	memset(&hints,0,sizeof(struct addrinfo));
	hints.ai_protocol = IPPROTO_UDP;
	hints.ai_family = AF_INET;

    //getting the address of the  server
	int status;
	status = getaddrinfo(argv[1],argv[2], &hints, &result);
	if (status==-1){
		printf("It seems like I can't find the host %s\n", argv[1]);
	}
	printf("Sending %s to the host : %s@%s\n", argv[3], argv[1], argv[2]);

    //creation of the socket
    int sd=socket(result->ai_family, result->ai_socktype, result->ai_protocol);

    //creation of the read request RRQ
	char RRQ[128]={0};
	RRQ[1];
	sprintf(RRQ+2,"%s", argv[3]);
	sprintf(RRQ+strlen(argv[3])+3, "NETASCII");

    //envoi de la requête
	sendto(sd, RRQ, strlen(argv[3])+12,0,res->ai_addr, res->ai_addrlen);

    //reception of the server's answer
	int numberReadBytes;
	char receivedBuffer[1024];
	struct sockaddr socketReceived;
	int socketReceiveSize;
	numberReadBytes=recvfrom(sd,receivedBuffer,1024,0,&socketReceived,&socketReceiveSize);

    //management of the server's answer
	if (receivedBuffer[1]==5{
		printf("Error code received from the server : \n%s\n", receivedBuffer+4);
		exit(EXIT_SUCCESS);
	}
	if(receivedBuffer[1]==3{
		printf("I received %d bytes", numberReadBytes-4);
		char ack[4]={0,4,0,0};
		ack[3]=receivedBuffer[3];
		sendto(sd,ack,4,0,&socketReceived,&socketReceiveSize);
	}
	
	return 0;
}
