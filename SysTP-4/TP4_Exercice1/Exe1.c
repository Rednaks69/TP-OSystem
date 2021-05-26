#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

int tab[10]; /* le tableau est une variable globale */
void *afficher(void *arg)
{
    int i;
    printf("je suis le thread d'affichage,\n mon numéro est %d et le numéro de mon père est %d \n",
           (int)pthread_self(), getpid());
    for (i = 0; i < 10; i++)
        printf("l'élément de l'indice %d est %d \n", i, tab[i]);
}
void *PlacerUN(void *arg)
{
    int i;
    printf("je suis le thread qui place des un,\n mon numéro est %d et le numéro de mon père est %d\n", (int)pthread_self(), getpid());
    for (i = 0; i < 10; i++)
        tab[i] = 1;
}
void *PlacerDEUX(void *arg)
{
    int i;
    printf("je suis le thread qui place des deux,\n mon numéro est %d et le numéro de mon père est %d \n", (int)pthread_self(), getpid());
    for (i = 0; i < 10; i++)
        tab[i] = 2;
}
int main(int argc, char **argv)
{
    int i;
    pthread_t th1, th2, th3;
    for (i = 0; i < 10; i++)
        tab[i] = i;
    pthread_create(&th1, NULL, afficher, NULL);
    pthread_create(&th2, NULL, PlacerUN, NULL);
    pthread_create(&th3, NULL, PlacerDEUX, NULL);
    printf("début de l'attente\n");
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    pthread_join(th3, NULL);
    printf("fin de l'attente\n");
    for (i = 0; i < 10; i++)
        printf("l'élément de position %d est %d\n", i, tab[i]);
}
