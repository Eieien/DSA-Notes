#ifndef DICT_H
#define DICT_H

#define MAX 10

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{

    struct Node *link;
    int val;

}*LIST, *Node;

typedef LIST Dictionary[MAX];

void initDict(Dictionary D);
void insertSorted(Dictionary D, int val);
void displayDict(Dictionary D);
void initDict(Dictionary D){

    for(int i = 0; i < MAX; i++){
        D[i] = NULL;
    }
}

void insertSorted(Dictionary D, int val){
    
    int key = val / 10;
    Node* curr;

    for(curr = &D[key]; *curr != NULL && (*curr)->val < val; curr = &(*curr)->link){}
    Node newnode = malloc(sizeof(struct Node));
    newnode->val = val;
    newnode->link = *curr;

    *curr = newnode;
}

void displayDict(Dictionary D){
    
    for(int i = 0; i < MAX; i++){
        printf("[%d]: ", i);

        for(Node curr = D[i]; curr != NULL; curr = curr->link){
            printf("%d->", curr->val);
        
        }

        printf("\n");
        
    }
}


#endif