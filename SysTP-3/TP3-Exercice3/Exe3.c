#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        for (int i = 0; i < atoi(argv[1]); i++)
        {
            if (fork() == 0)
            {
                printf("[son] pid %d from [parent] pid %d\n", getpid(), getppid());
                exit(0);
                wait(NULL);
            }
        }
    }
}