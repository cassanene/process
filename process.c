#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    int status;
    int pid;
    int child;

    for (int x; x < 2; x++)
    {
        pid = fork();
        if (pid == 0)
        {
            //child sleeps for random # of time
            for (int i = 0; i < (rand() % 30 + 1); i++)
            {

                // child sleeps for random amount of times
                printf("Child Pid = %d is going to sleep\n", getpid());
                // int sleepSecs;
                sleep(rand() % 10 + 1);
            }

            printf("Child Pid = %d is up! Where is my parent = %d?\n", getpid(), getppid());
            exit(0);
            break;
        }
        if (pid == -1)
        {
            break;
        }
        else
        {
            wait(&status);
            printf("Child = %d has finished\n", getpid() + 1);
            break;
        }
    }
    printf("Program terminating...\n");

    return 0;
}
