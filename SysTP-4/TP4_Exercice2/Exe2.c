#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

int tab[10];
void *helloworld(void *arg)
{
    printf("hello World! pid= %d tid=%ld \n", getpid(), pthread_self());
    return NULL;
}
int main(int argc, char **argv)
{
    int i, nb;
    int j = 1;
    int *ptr;
    pthread_t *threads;
    nb = atoi(argv[1]);
    printf("début de l'attente\n");
    for (i = 0; i < nb; i++)
    {
        pthread_create(&threads[i], NULL, helloworld, &j);
    }
    for (i = 0; i < nb; i++)
    {
        pthread_join(threads[i], (void **)&ptr);
    }
    printf("fin de l'attente\n");
    return 0;
}