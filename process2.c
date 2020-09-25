#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
    int status;
    int pid;
    int child;
    pid = fork();
    if (pid == 0)
    {
        //child sleeps for random # of time
        int i;
        for (i = 0; i < (rand() % 30 + 1); i++)
        {

            // child sleeps for random amount of times
            printf("Child Pid = %d is going to sleep\n", getpid());
            // int sleepSecs;
            sleep(rand() % 10 + 1);
        }

        printf("Child Pid = %d is up! Where is my parent = %d?\n", getpid(), getppid());
        exit(0);
    }
    if (pid == -1)
    {
    }
    else
    {
        wait(&status);
        printf("Child = %d has finished\n", getpid() + 1);
    }
    printf("Program terminating...\n");
}
