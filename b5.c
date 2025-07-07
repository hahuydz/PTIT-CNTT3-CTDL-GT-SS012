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
void deleteByValue(node** head, node** tail, int value);

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

    printf("\nDanh sach ban dau:\n");
    printList(head);

    printf("\nNhap gia tri muon xoa: ");
    scanf("%d", &value);

    deleteByValue(&head, &tail, value);

    printf("\nDanh sach sau khi xoa gia tri %d:\n", value);
    printList(head);

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

void deleteByValue(node** head, node** tail, int value) {
    node* current = *head;

    while (current != NULL) {
        node* nextNode = current->next;

        if (current->data == value) {
            // Node đầu
            if (current == *head) {
                *head = current->next;
                if (*head != NULL)
                    (*head)->prev = NULL;
                else
                    *tail = NULL;
            }
            // Node cuối
            else if (current == *tail) {
                *tail = current->prev;
                (*tail)->next = NULL;
            }
            // Node giữa
            else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }

            free(current);
        }

        current = nextNode;
    }
}
