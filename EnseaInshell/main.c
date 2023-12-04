#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>



#include "constantHeader.h"
#include "program.c"

int main(){
    char console_input[MAX_INPUT_SIZE];
    int son_status;

    write (STDOUT_FILENO,WELCOME_MSG,strlen(WELCOME_MSG));  

    

    while(1){

        write (STDOUT_FILENO,ENSEASH,strlen(ENSEASH));   
        int nbBytes=read(STDIN_FILENO,console_input,MAX_INPUT_SIZE);

        console_input[nbBytes-1]=0;

       

        pid_t pid = fork();

        if (pid==-1){
            perror("fork failed");
            exit(EXIT_FAILURE);   
        }

        //in the son process
        if(pid==0){ 

            if (strcmp(console_input,"fortune")==0){
                execlp("fortune","fortune",NULL);
                perror("execlp failed");
                exit(EXIT_FAILURE);
            }   

            if (strcmp(console_input,"date")==0){
                execlp("date","date",NULL);
                perror("execlp failed");
                exit(EXIT_FAILURE);
            }   
        }
            
        //in the parent process
        else{
        wait(&son_status);
        }

       
    }


    return 0;
}

