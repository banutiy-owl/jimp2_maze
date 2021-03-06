#include <stdio.h>
#include <stdlib.h>
#include "Utility.h"

#ifndef BFS_H
#define BFS_H


struct k_node {
    int value;
    struct k_node* next;
};

struct queue {
    struct k_node* front;
    struct k_node* back;
};

struct k_node* NewNode(int numer);
struct queue* NewQueue() ;
void add_to_queue(struct queue* q, int item);
int remove_from_queue(struct queue* q);
int bfs(struct Graph* g, int start);


#endif