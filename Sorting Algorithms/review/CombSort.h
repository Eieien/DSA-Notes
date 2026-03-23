#ifndef COMBSORT_H
#define COMBSORT_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

void CombSort(int arr[], int len){

    int gap = len / 1.3;

    while(gap > 0){

        if(gap < 1) gap = 1;

        for(int i = gap; i < len; i++){

            if(arr[i - gap] > arr[i]){
                int temp = arr[i - gap];
                arr[i - gap] = arr[i];
                arr[i] = temp;
            }

        }

        gap /= 1.3;

    }

}

#endif