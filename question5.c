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
        //int wait_return = wait(NULL);
        printf("child has pid: %d\n", getpid());
        //printf("the return value of wait() is %d", wait_return);
    }
    else {
        //parent process
        int wait_return = wait(NULL);
        printf("parent has pid: %d\n", getpid());
        printf("the return value of wait() is %d", wait_return);
        
    }
}
