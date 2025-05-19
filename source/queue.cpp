#include<stdio.h>
#include"../header/queue.h"
#include<iostream>

void print_menu(void)
{
    printf(" _________________________________________________________________________________________________________________________________ \n");
    printf("| |||||     |||||    |||||   |||||||||    |||||||      |||||      |||||     |||||   ||||||||    ||||||||   |||||  ||||||  |||||| |\n");
    printf("| |||||||||||||||    || ||      |||         |||      || |||       |||||||||||||||   |||           ||||   || |||     |||    |||   |\n");
    printf("| ||||| ||| |||||    || ||      |||         |||    ||   |||       ||||| ||| |||||   ||||||||      |||| ||   |||     |||    |||   |\n");
    printf("| ||||| ||| |||||    |||||      |||         |||  ||     |||       ||||| ||| |||||   |||           |||||     |||     |||    |||   |\n");
    printf("| ||||| ||| |||||   |||||||  |||||||||     ||||||      |||||      ||||| ||| |||||   ||||||||     |||||||   |||||    ||||||||||   |\n");
    printf(" _________________________________________________________________________________________________________________________________\n");
    printf("|                                                [1] - CREER UNE FILE                                                            |\n");
    printf("|                                              [2] - AJOUTEZ UN ELEMENT                                                          |\n");
    printf("|                                             [3] - SUPPRIMER UN ELEMENT                                                         |\n");
    printf("|                                            [4] - AFFICHER LES ELEMENTS                                                         |\n");
    printf("|                                         [5] - AFFICHER LE PREMIER ELEMENT                                                      |\n");
    printf("|                                               [6] - VIDER LA FILE                                                              |\n");
    printf("|                                            [7] - VERIFIER SI LA FILE EST VIDE                                                         |\n");
    printf("|                                      [8] - VERIFIER SI LA FILE EST PLEINE                                                      |\n");
    printf("|                                      [9] - AFFICHER LA TAILLE DE LA FILE                                                       |\n");
    printf("|                                         [10] - RECHERCHER UN ELEMENT                                                           |\n");
    printf("|                                           [11] - INVERSER LA FILE                                                              |\n");
    printf("|                                  [12] - TRIER LA FILE PAR ORDRE CROISSANT                                                      |\n");
    printf("|                                 [13] - TRIER LA FILE PAR ORDRE DECROISSANT                                                     |\n");
    printf("|                                                  [14] - EXIT                                                                   |\n");
    printf("__________________________________________________________________________________________________________________________________\n\n");
    printf("Choissisez une option : ");
}
/*---------------------------------------------------------------------------------------*/
//verifier si file vide
bool Is_Empty_Queue(void)
{
    if (first == NULL && last == NULL)
    {
        return true;
    }
    return false;
}

/*---------------------------------------------------------------------------------------*/
//afficher la file 
void Print_Queue(void)
{
    if (Is_Empty_Queue())
    {
        printf("LA FILE EST VIDE, IL Y A RIEN A AFFICHER");
        return;
    }

    QUEUE *temp = first;
    
    printf("[");
    
    while (temp != NULL)
    {
        printf("%d", temp->value);
        
        if (temp->next != NULL)
            printf(",");

        temp = temp->next;
    }
    printf("]\n");
}

/*---------------------------------------------------------------------------------------*/
//afficher la taille de la file 
int Queue_Lenght(void)
{
    return nb_element;
}

/*---------------------------------------------------------------------------------------*/
//afficher le premier element de la file 
int Queue_First(void)
{
    if(Is_Empty_Queue())
        exit(1);
    
    return first->value;
}

/*---------------------------------------------------------------------------------------*/
//afficher le dernier element de la file 
int Queue_Last(void)
{
    if(Is_Empty_Queue())
        exit(1);

    return last->value;
}

/*---------------------------------------------------------------------------------------*/
//ajouter un element dans la file
void Enqueue(int val)
{
    QUEUE *element;    

    element = new QUEUE;

    if (element == NULL)
    {
        fprintf(stderr, "Probleme lors de l'allocation dynamique de la memoire");
        exit(EXIT_FAILURE);
    }

    element->value = val;
    element->next = NULL; 
    
    if (Is_Empty_Queue())
    {
        first = element;
        last = element;   
    }else
    {
        last->next = element;
        last= element;
    }
    nb_element ++;
}

/*---------------------------------------------------------------------------------------*/
//supprimer un element dans la file
void Dequeue(void)
{
    if (Is_Empty_Queue())
    {
        printf("La file est vide\n");
        return; 
    }

    QUEUE *temp = first;

    if (first == last)
    {
        first = NULL;
        last = NULL;
    }
    else
        first = first->next;
    
    delete(temp);
    nb_element --;
}
/*---------------------------------------------------------------------------------------*/
//vider la file 
void Clear_Queue(void)
{
    if (Is_Empty_Queue())
    {
        printf("la FILE est deja vide");
        return;
    } 
    while (!Is_Empty_Queue())
    {
        Dequeue();
    }
}