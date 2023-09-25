# OSTEP-Chapter5
Chapter 5:
Question 1: The value of the variable x stays the same(100 in my code) as in the parent process. If we change the values of x in both the parent process(changed it to 1 in my code) and child process(changed it to -1 in my code), these values will not be the same anymore.

Question 2: In my experiment, both the parent and child processes can access the file descriptor. And they can write to the same file concurrently withour error, although the order of messages could be wrong, but not in my experiment outcome.

Question 3: I let the child process to issue a file IO on purpose, so the scheduler will switch to the parent process and print the "Hello" first.

Question 4: I think there are so many variants of the same call becuase each variant correspnds to a different way to invoke the exec() system call(full path or relative path, input as a list or as a vector, etc).

Question 5: The return value of wait() is the process id of the child process, i.e. the process we are waiting for to complete first. If we use wait() in the child, wait() will return -1, indicating wait() failed to execute.

Question 6: waitpid() would be useful when the parent process has several child processes and we want to wait for a specific child. Or we can use waitpid() to check on the status of a child process.

Question 7: There is no output from printf().

Chapter 6:
For context switch measurement, the result is 4.045050ms for each swich (running on Amazon EC2 sercer, CPU affinity set to be a single CPU).
For System call measurement, the reasut is 0.003956 ms for each getpid() (running on Macbook).


Chapter 7:
Question 1: For SJF,the average reponse time is 200 seconds and the average turnaround time is 400 seconds.
For FIFO, the average reponse time is 200 seconds and the average turnaround time is 400 seconds.

Question 2: For SJF,the average reponse time is 133.33 seconds and the average turnaround time is 333.33 seconds.
For FIFO, the average reponse time is 133.33 seconds and the average turnaround time is 333.33 seconds.

Question 3: For RR, the average reponse time is 1 seconds and average turnaround time is 456.67 seconds.

Question 4: For such workloads that all jobs arrive at the same time and we also assume FIFO alwaysy starts from shorter jobs. Or for workloads that all jobs arrive at the same time and have the same size.

Question 5: For workloads that all jobs arrive at the same time and have the same size, with the quantum length equals to the size of each job.

Question 6: The response time with SJF increases almost linearly as job lengths increase.

Question 6: The response time with RR increases almost linearly as quantum increases.




