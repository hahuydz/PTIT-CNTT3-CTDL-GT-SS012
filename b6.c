//
// Created by admin on 7/6/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} node;

node* createNode(int value);
void printList(node* head);
int getLength(node* head);
node* findMiddleNode(node* head);

int main() {
    int n, value;
    node *head = NULL, *tail = NULL;

    printf("Nhap so luong node: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Nhap gia tri node thu %d: ", i);
        scanf("%d", &value);

        node* newNode = createNode(value);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    printf("\nDanh sach hien tai:\n");
    printList(head);

    node* middle = findMiddleNode(head);
    if (middle != NULL) {
        printf("Node giua: %d\n", middle->data);
    } else {
        printf("Danh sach rong!\n");
    }

    return 0;
}

node* createNode(int value) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Khong du bo nho!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void printList(node* head) {
    node* current = head;
    printf("NULL->");
    while (current != NULL) {
        printf("%d<->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int getLength(node* head) {
    int count = 0;
    node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

node* findMiddleNode(node* head) {
    int length = getLength(head);
    if (length == 0) {
        return NULL;
    }
    int midPos = length / 2 + 1;

    node* current = head;
    for (int i = 1; i < midPos; i++) {
        current = current->next;
    }
    return current;
}
