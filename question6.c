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
        
        printf("child has pid: %d\n", getpid());
        
    }
    else {
        //parent process
        int status;
        int wait_return = waitpid((pid_t) -1,&status,WCONTINUED);
        printf("parent has pid: %d\n", getpid());
        printf("the return value of waitpid() is %d", wait_return);
        
    }
}
