#pragma once

#ifndef __QUEUE__H__
#define __QUEUE__H__

//Definition d'une file
typedef struct QUEUE
{
    int value;
    struct QUEUE *next;
}QUEUE, *queue;

//Parametres definissant une file et le principe FIFO
static QUEUE *first = NULL;
static QUEUE *last  = NULL;
static int nb_element = 0;

//Prototypes des fonctions  
void print_menu(void);
bool Is_Empty_Queue(void);
void Enqueue(int val);
void Clear_Queue(void);
void Print_Queue(void);
void Dequeue(void);
int Queue_Lenght(void);
int Queue_First(void);
int Queue_Last(void);
#endif