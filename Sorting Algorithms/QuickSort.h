#ifndef QUICKSORT_H
#define QUICKSORT_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>


int HoarePartition(int arr[], int left, int right){

    int pivot = arr[left];
    int i = left;
    int j = right;
    
    while(i < j){
        
        while(arr[i] < pivot){
            i++;
        }
        
        while(arr[j] > pivot){
            j--;
        }
        
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    printf("%d %d %d \n", pivot, arr[i], arr[j]);

    return j;
}

int LomutoPartition(int arr[], int left, int right){
    int pivot = right;
    int j = left;
    int i = j - 1;

    while(j < pivot){
        
        if(arr[j] <= arr[pivot]){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

        j++;
    }
    printf("PARTIONING\n");
    int temp = arr[i + 1];
    arr[i + 1] = arr[pivot];
    arr[pivot] = temp;

    return i + 1; // pivot index
}

void quickSort(int arr[], int left, int right){
    
    if(left < right){
        // int partition = HoarePartition(arr, left, right);

        int partition = LomutoPartition(arr, left, right);

        printf("quick Sorting\n");

        quickSort(arr, left, partition - 1);
        quickSort(arr, partition + 1, right);
    }
    
}



#endif