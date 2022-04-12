#ifndef UTILITY_H
#define UTILITY_H
#include <ctype.h>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

struct AdjListNode
{
    int dest;
    int weight;
    struct AdjListNode* next;
};
struct AdjList
{

    // Pointer to head node of list
    struct AdjListNode* head;
};
struct Graph
{
    int num_vert;
    struct AdjList* array;
    int cols;
    int rows;
};


void otworzenie_pliku_i_sprawdzenie_danych(char * plikwej, graf_str** graf);	
#endif