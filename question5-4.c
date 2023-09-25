#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>


int main(){
    
    int rc = fork();
    if (rc < 0){
        //fork failed
        fprintf(stderr,"fork failed\n");
        exit(1);
    }
    else if (rc ==0) {
        //child process

        //try execl()
        printf("runing execl:\n");
        char *file = "/usr/bin/ls";
        execl(file,file, NULL);

        //try execlp()
        printf("runing execlp:\n");
        execl("ls","ls", NULL);


        //try execvp()
        printf("runing execvp:\n");
        char *myargs[2];
        myargs[0] = strdup("ls");
        myargs[1] = NULL;
        execvp(myargs[0], myargs);
    }
    else {
        //parent process
        wait(NULL);
        printf("back to parent process\n");
        
    }

}