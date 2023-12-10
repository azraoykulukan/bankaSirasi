#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int ID;
    struct Node* next;
}node;

typedef struct Queue {
    struct Node* front;
    struct Node* rear;
}queue;

void initializeQueue(queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(queue* q, int id) {
    node* newNode = (node*)malloc(sizeof(node));
    node* current = q->front;

    newNode->ID = id;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        if (id == 1) {
            // ID=1 ise sýradan müþteri, kuyruðun sonuna ekle
            q->rear->next = newNode;
            q->rear = newNode;
        } else if (id == 2) {
        	int count=0;
        while (current != NULL) {
        count++;
        if(count==2) break;
        current = current->next;
    }
    	newNode->next = current->next;
   		current->next = newNode;
    
        } else if (id == 3) {
            // ID=3 ise 65 yaþ üstü, kuyruðun baþýna ekle
            newNode->next = q->front;
            q->front = newNode;
        }
    }
}

int dequeue(queue* q) {
    if (q->front == NULL) {
        printf("Kuyruk bos.\n");
        return -1;
    } else {
        node* temp = q->front;
        int id = temp->ID;

        q->front = q->front->next;
        free(temp);

        if (q->front == NULL) {
            q->rear = NULL;
        }

        return id;
    }
}

void displayQueue(queue* q) {
    node* current = q->front;

    printf("Kuyruk sirasi: ");
    while (current != NULL) {
        printf("ID%d ", current->ID);
        current = current->next;
    }
    printf("\n");
}

int main() {
    queue q;
    initializeQueue(&q);

    int choice, id;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Kisi Ekle\n");
        printf("2. Kisi Isleme Al\n");
        printf("3. Kuyrugu Goruntule\n");
        printf("0. Cikis\n");
        printf("Seciminizi yapiniz: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Kisi ID giriniz: ");
                scanf("%d", &id);
                enqueue(&q, id);
                break;
            case 2:
                id = dequeue(&q);
                if (id != -1) {
                    printf("Isleme alinan kisi ID%d\n", id);
                }
                break;
            case 3:
                displayQueue(&q);
                break;
            case 0:
                printf("Programdan cikiliyor.\n");
                break;
            default:
                printf("Gecersiz secim. Tekrar deneyiniz.\n");
        }
    } while (choice != 0);

    return 0;
}

