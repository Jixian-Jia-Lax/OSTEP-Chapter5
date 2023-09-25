#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int x = 100;
    printf("before fork, the value of x in the parent process is: %d\n", x);
    int rc = fork();
    if (rc < 0){
        //fork failed
        fprintf(stderr,"fork failed\n");
        exit(1);
    }
    else if (rc ==0) {
        //child process
        printf("after fork,the value of x in the child process is: %d\n", x);
        x = -1; //change the value of x in child
        printf("after fork,the CHANGED value of x in the child process is: %d\n", x);
    }
    else {
        printf("after fork, the value of x in the parent process is: %d\n", x);

        x= 1;
        printf("after fork,the CHANGED value of x in the parent process is: %d\n", x);
    }

}
