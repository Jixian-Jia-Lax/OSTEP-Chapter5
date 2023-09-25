#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(){
    int pipefds[2];
    pipe(pipefds);
    
    int child_1 = fork();
    int child_2 = fork();
    if (child_1 < 0 || child_2 <0){
        //fork failed
        fprintf(stderr,"fork failed\n");
        exit(1);
    }
    else if (child_1 ==0) {
        //child process 1
        write(pipefds[1],"Hello!",strlen("Hello!"));
        exit(0);
        
    }
    else if (child_2 == 0){
        //child process 2
        char buffer[20];

        read(pipefds[0], buffer, sizeof(buffer) - 1);
        printf("This is the message from the other side of pipe(): %s\n",buffer);
        exit(0);
    }
    else{
        waitpid(child_1,NULL,WEXITED);
        waitpid(child_2,NULL,WEXITED);
        exit(1);
    }
}
