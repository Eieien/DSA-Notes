#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;


void append(Node **head, int data);
void shellSort(Node *head);
void printList(Node *head);



int main() {
    Node *head = NULL;
    int arr[] = {23, 3, 12, 55, 2, 1};

    for (int i = 0; i < 6; i++)
        append(&head, arr[i]);

    shellSort(head);
    printList(head);
}



//inserts last.
void append(Node **head, int data) {
    Node *node= malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    if (!*head) {
        node->prev = NULL;
        *head = node;
        return;
    }

    Node *t = *head;
    while (t->next != NULL) t = t->next;
    t->next = node;
    node->prev = t;
}

//shell
void shellSort(Node *head) {
    int n = 0;
    Node *trav = head;

    while (trav) { n++; trav = trav->next; } 

    for (int gap = n / 2; gap > 0; gap /= 2) {   
        for (int i = gap; i < n; i++) {
            Node *cur = head;
            for (int k = 0; k < i; k++) cur = cur->next;

            int temp = cur->data;
            Node *j = cur;

            while (j->prev && j->prev->data > temp) { // keeps backtracking while condition is true. If prev node is larger, you must swap, and that prev node becomes ur current. keep going til the condition no longer fits.
                j->data = j->prev->data;
                j = j->prev;
            }
            j->data = temp;
            printList(head);
        }
    }
}

void printList(Node *head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
