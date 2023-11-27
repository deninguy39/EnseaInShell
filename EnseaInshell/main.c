#include <stdio.h>
#include <unistd.h>
#include <string.h>


#include "constantHeader.h"
#include "program.c"

int main(){
    char console_input[MAX_INPUT_SIZE];
    int son_status;

    write (STDOUT_FILENO,WELCOME_MSG,strlen(WELCOME_MSG));  

    while(1){

        write (STDOUT_FILENO,ENSEASH,strlen(ENSEASH));   
        read(STDIN_FILENO,console_input,MAX_INPUT_SIZE);

        //in the case we want to stop (it doesn't work, I can't exit)
        if (strcmp(console_input, "exit") == 0) {
            break; 
        }

        pid_t pid = fork();

        if (pid==-1){
            perror("fork failed");
        }

        //in the son process
        if(pid==0){
            execlp("fortune","fortune",NULL);
            perror("execlp failed");
        }

        //in the parent process
        else{
        wait(&son_status);
        }

       
    }


    return 0;
}

