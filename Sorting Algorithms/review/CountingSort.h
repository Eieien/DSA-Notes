#ifndef COUNTING_H
#define COUNTING_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

void CountingSort(int arr[], int len){
    
    int max = arr[0];

    for(int i = 0; i < len; i++){
        if(max < arr[i])max = arr[i];
    }

    int* freqArr = (int*)calloc(max + 1, sizeof(int));
    int* output = (int*)malloc(sizeof(int) * len);

    for(int i = 0; i < len; i++){
        freqArr[arr[i]]++;
    }

    for(int i = 0; i < max ;i++){
        freqArr[i + 1] += freqArr[i];
    }

    for(int i = len; i >= 0; i--){
        output[freqArr[arr[i]] - 1] = arr[i];
        freqArr[arr[i]]--;
    }

    for(int i = 0; i < len; i++){
        arr[i] = output[i];
    }

}


#endif