#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(){
    
    int rc = fork();
    if (rc < 0){
        //fork failed
        fprintf(stderr,"fork failed\n");
        exit(1);
    }
    else if (rc ==0) {
        //child process
        fclose(stdout);
        printf("print something after closing stdout");
        
    }
    else {
        //parent process
        wait(NULL);
        
    }
}
