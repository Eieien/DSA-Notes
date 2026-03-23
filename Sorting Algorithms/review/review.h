#ifndef REVIEW_H
#define REVIEW_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

void display(int arr[], int len){

    printf("\n");
    for(int i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
}

void insertionSort(int arr[], int len){

    for(int i = 1; i < len; i++){
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

}

void ShellSort(int arr[], int len){

    int gap = len / 2;

    while(gap >= 1){
        
        for(int i = gap; i < len; i++){

            int j = i;
            int key = arr[i];
            while(j >= gap && arr[j - gap] > key){
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = key;
        }
        gap /= 2;
    }

}

void SelectionSort(int arr[], int len){

    for(int i = 0; i < len - 1; i++){

        int min = i;
        
        for(int j = i + 1; j < len; j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        if(arr[min] < arr[i]){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

}

void CountingSort(int arr[], int len){
    
    int max = arr[0];

    for(int i =0 ; i < len; i++){
        if(max < arr[i]) max= arr[i];
    }

    int* freq = (int*)calloc(max + 1, sizeof(int));
    int* output = (int*)malloc(sizeof(int) * len);

    for(int i = 0; i < len; i++){
        freq[arr[i]]++;
    }
    
    // Prefix sum;
    for(int i = 1; i <= max; i++){
        freq[i] += freq[i - 1];
    }


    //Inserting Process
    for(int i = len -1; i >= 0; i--){
        output[freq[arr[i]] - 1] = arr[i];
        freq[arr[i]]--;
    }

    for(int i = 0; i < len; i++){
        arr[i] = output[i];
    }
    free(freq);
    free(output);
}

void GnomeSort(int arr[], int len){

    int i = 1;
    while(i < len){
        if(arr[i] < arr[i - 1] && i > 0){
            int temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
            i--;
        }else{
            i++;
        }
    }
}

void BubbleSort(int arr[], int len){

    for(int i = 0; i < len - 1; i++){

        for(int j = i; j < len; j++){
            if(arr[j] < arr[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp; 
            }
        }
    }

}



int HoarePartitioning(int arr[], int l, int r){

    int i = l;
    int j = r;
    int pivot = arr[l];
    while(i < j){

        while(arr[i] < pivot){
            i++;
        }

        while(arr[j] > pivot){
            j--;
        }

        if(i < j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;

        }
    }
    return j;

}

int LomutoPartitioning(int arr[], int l, int r){

    int j = l;
    int i = l -1;
    int pivot = r;
    
    while(j < pivot){
        if(arr[j] <= arr[pivot]){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        j++;
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[pivot];
    arr[pivot] = temp;

    return i + 1;

}

void QuickSort(int arr[], int l, int r){

    if(l < r){

        int p = HoarePartitioning(arr, l, r);
        QuickSort(arr, l, p);

        QuickSort(arr, p + 1, r);
    }
}


#endif