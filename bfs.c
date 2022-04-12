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
    if (q->back==NULL) {
        q->front = item;
    }
    q->back=item;
    q->back->next=item;
}

int remove_from_queue(struct queue* q) {
    if (q->front==NULL) {
        print("Kolejka jest pusta");
        return -1;
    }
    int last_item=q->back->value;
    q->front=q->front->next;
    if (q->front==NULL) {
        print("Kolejka jest pusta");
    }

    return last_item;

}

int bfs(struct Graph* g, int start) {
    struct queue* q = NewQueue();
    int u;
    int new;
    int* flag = malloc(g->num_vert * sizeof(int));
    int* prev =malloc(g->num_vert * sizeof(int));
    for (int i=0; i<g->num_vert; i++) {
        flag[i]=0;
        prev[i]=0;
    }
    add_to_queue(q,start);
    int n=0;
    int *neighbours=malloc(g->num_vert*g->num_vert);
    flag[start]=1;
    while (q->front!=NULL){
        u=remove_from_queue(q);
        while (g->array->head!=NULL) {
            neighbours[n]=g->array->head->dest;
            n++;
            g->array->head->next;
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
    for (int i=0;i<g->num_vert;i++) {
        if (flag[i]!=1){
        return -1; // nie jest spojny
        }

    }
    return 0; //jest spojny
}




