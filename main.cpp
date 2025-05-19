#include<iostream>
#include<stdio.h>
#include"header/queue.h"

int main(void)
{
    Enqueue(14);
    Enqueue(-26);
    Enqueue(143);

    Print_Queue();
    printf("La taille de la file est:%d", Queue_Lenght());
    printf("\nler premier element de la file est :%d", Queue_First());
    printf("\nle derenier element de la file est :%d", Queue_Last());

    Dequeue();
        printf("\nLa taille de la file est:%d", Queue_Lenght());
        printf("\nler premier element de la file est :%d", Queue_First());
        printf("\nle derenier element de la file est :%d", Queue_Last());

    Clear_Queue();
        printf("\nLa taille de la file est:%d", Queue_Lenght());
        printf("\nler premier element de la file est :%d", Queue_First());
        printf("\nle derenier element de la file est :%d", Queue_Last());

    return 0;
}