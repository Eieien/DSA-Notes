#ifndef TOURNAMENT_H
#define TOURNAMENT_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<limits.h>

int parent(int idx){
    return (idx - 1) / 2;
}

int leftChild(int idx){
    return (idx * 2) + 1;
}

int rightChild(int idx){
    return (idx * 2) + 2;
}

int min(int L, int R){
    return (L < R) ? L : R;
}

void displayTree(int tree[], int treeSize){

    printf("\n");
    for(int i = 0; i < treeSize; i++){
        printf("%d ", (tree[i] == INT_MAX) ? 99 : tree[i]);
    }
    printf("\n");
}

int winner(int tree[], int offset){

    for(int i = offset - 1; i >= 0; i--){
        tree[i] = min(tree[leftChild(i)], tree[rightChild(i)]);
    }

    return tree[0];
}

void updateTree(int tree[] ,int champion, int treeSize){
    int i = 0;
    while(leftChild(i) < treeSize){
        if(tree[leftChild(i)] == champion){
            i = leftChild(i);
        }

        if(tree[rightChild(i)] == champion){
            i = rightChild(i);
        }
    }

    tree[i] = INT_MAX;

}

void initTree(int tree[], int treeSize){

    for(int i = 0 ; i < treeSize; i++){
        tree[i] = INT_MAX;
    }

}

void OfflineTournamentSort(int arr[], int len){

    int treeSize = len * 2 - 1;
    int tree[treeSize];
    initTree(tree, treeSize);
    int offset = len - 1;

    for(int i = 0; i < len; i++){
        tree[offset + i] = arr[i];
    }
    for(int i = 0; i < len; i++){
        int champion = winner(tree, offset);
        updateTree(tree, champion, treeSize);
        arr[i] = champion;
    }
    display(tree, treeSize);

}


#endif