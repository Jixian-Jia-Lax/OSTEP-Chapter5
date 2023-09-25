# OSTEP-Chapter5

Question 1: The value of the variable x stays the same(100 in my code) as in the parent process. If we change the values of x in both the parent process(changed it to 1 in my code) and child process(changed it to -1 in my code), these values will not be the same anymore.

Question 2: In my experiment, both the parent and child processes can access the file descriptor. And they can write to the same file concurrently withour error, although the order of messages could be wrong, but not in my experiment outcome.

Question 3: I let the child process to issue a file IO on purpose, so the scheduler will switch to the parent process and print the "Hello" first.

Question 4: I think there are so many variants of the same call becuase each variant correspnds to a different way to invoke the exec() system call(full path or relative path, input as a list or as a vector, etc).

Question 5: The return value of wait() is the process id of the child process, i.e. the process we are waiting for to complete first. If we use wait() in the child, wait() will return -1, indicating wait() failed to execute.
