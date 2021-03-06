#include <stdio.h>
#include <stdlib.h>
#include "bfs.h"
#include "Utility.h"

struct k_node* NewNode(int nv) {
  struct k_node* new_node = malloc(sizeof(struct k_node));
  new_node->value = nv;
  new_node->next = NULL;
  return new_node;
}

struct queue* NewQueue() {
  struct queue* new_queue = malloc(sizeof(struct queue));
  new_queue->front = NULL;
  new_queue->back = NULL;
  return new_queue;
}

void add_to_queue(struct queue* q, int item) {
    struct k_node* temp=NewNode(item);
    if (q->back==NULL) {
        q->front = temp;
    }
    q->back=temp;
    q->back->next=temp;
}

int remove_from_queue(struct queue* q) {
    if (q->front==NULL) {
        printf("Kolejka jest pusta");
        return -1;
    }
    int last_item=q->back->value;
    q->front=q->front->next;
    if (q->front==NULL) {
        printf("Kolejka jest pusta");
    }

    return last_item;

}

int bfs(struct Graf* g, int start) {
    struct queue* q = NewQueue();
    int u;
    int new;
    int* flag = malloc(g->l_wierz * sizeof(int));
    int* prev =malloc(g->l_wierz * sizeof(int));
    for (int i=0; i<g->l_wierz; i++) {
        flag[i]=0;
        prev[i]=0;
    }
    add_to_queue(q,start);
    int n=0;
    int *neighbours=malloc(g->l_wierz*g->l_wierz);
    flag[start]=1;
    while (q->front!=NULL){
        u=remove_from_queue(q);
        while (g->t->teges!=NULL) {
            neighbours[n]=g->t->teges->wierz;
            n++;
            g->t->teges->next;
        }
        for ( int i = 0; i <n;i++) {
            new=neighbours[i];
            if(flag[new]!=1) {
                add_to_queue(q,u);
                flag[new]=1;
                prev[new]=u;
            }
        }
        
    }
    for (int i=0;i<g->l_wierz;i++) {
        if (flag[i]!=1){
        return -1; // nie jest spojny
        }

    }
    return 0; //jest spojny
}




