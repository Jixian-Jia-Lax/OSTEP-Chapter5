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
        printf("Hello!\n");
    }
    else {
        //parent process
        int fp = open("wait.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
         write(fp,"message for IO\n",strlen("message for IO\n"));
        close(fp);
        printf("goodbye\n");
        
    }

}