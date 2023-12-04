#include <stdio.h>
#include <string.h>
#include<unistd.h>

#include "constantHeader.h"



void prompt(){
     write (STDOUT_FILENO,WELCOME_MSG,strlen(WELCOME_MSG));  
     write (STDOUT_FILENO,QUIT,strlen(QUIT));  
     write (STDOUT_FILENO,ENSEASH,strlen(ENSEASH));     
     write (STDOUT_FILENO,BYE,strlen(BYE));  
}

