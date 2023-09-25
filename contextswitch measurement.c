#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sched.h>


#define LOOP 100000

int main(){

    cpu_set_t  mask;

    CPU_ZERO(&mask);
    CPU_SET(1, &mask);
    sched_setaffinity(0, sizeof(mask), &mask);
    struct timeval time_before;
    struct timeval time_after;
    gettimeofday(&time_before,NULL);

    int pipefds[2];
    pipe(pipefds);
    
    int child = fork();
    if (child <0){
        //fork failed
        fprintf(stderr,"fork failed\n");
        exit(1);
    }
    if (child ==0) {
        //child process 
        int i;
        for (i = 0; i< LOOP; i++){
        write(pipefds[1],"Hello!",strlen("Hello!"));
        }
        exit(0);
        
    }
    else {
        //parent process
        
        int i;
        for (i = 0; i< LOOP; i++){
        read(pipefds[0], NULL,strlen("Hello!"));
        }
        gettimeofday(&time_after,NULL);
        printf("A single context switch takes %f ms", 
        (double)(time_after.tv_usec - time_before.tv_usec)/LOOP);

        return 0;
    }
   
}
