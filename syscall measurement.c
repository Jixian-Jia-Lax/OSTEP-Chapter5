#define LOOP 1000000

#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdio.h>

int main(){
    struct timeval time_before;
    struct timeval time_after;

    gettimeofday(&time_before,NULL);

    //run system calls in a for loop
    int i;
    for (i = 0; i< LOOP; i++){
        getpid();
    }

    gettimeofday(&time_after,NULL);

    printf("A single getpid() takes %f ms", (double)(time_after.tv_usec - time_before.tv_usec)/LOOP);
    return 0;
    
}