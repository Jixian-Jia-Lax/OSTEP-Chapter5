#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(){
    int fp;
    fp = open("text.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fp == -1){
        fprintf(stderr,"open failed\n");
    }
    int err = write(fp,"This message was sent before fork\n",strlen("This message was sent before fork\n"));
    if (err == -1){
            printf("error while writing before fork\n");
        }

    int rc = fork();
    if (rc < 0){
        //fork failed
        fprintf(stderr,"fork failed\n");
        exit(1);
    }
    else if (rc ==0) {
        //child process
        int err = write(fp,"This message was sent from the child process\n",strlen("This message was sent from the child process\n"));
        err =  write(fp, "another message from child\n", strlen("another message from child\n"));
        if (err == -1){
            printf("error while writing from the child process\n");
        }
        //close(fp);
        
    }
    else {
        //parent process
        int err = write(fp,"This message was sent from the parent process\n",strlen("This message was sent from the parent process\n"));
        err =  write(fp, "another message from parent\n", strlen("another message from parent\n"));

        //wait(NULL);
        if (err == -1){
            printf("error while writing from the parent process\n");
        }
        //close(fp);
    }

}
