#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "header.h"

// Inisialisasi Queue
void initializeQueue(Queue *queue) {
    queue->front = queue->rear = NULL;
    queue->size = 0;
}

// Inisialisai Stack
void initializeStack(Stack *stack) {
    stack->top = NULL;
    stack->size = 0;
}

// Memeriksa apakah Queue kosong 
bool isQueueEmpty(Queue *queue) {
    return (queue->front == NULL);
}

// Memeriksa apakah Stack kosong
bool isStackEmpty(Stack *stack) {
    return stack->top == NULL;
}

// Fungsi untuk membuat linked list dari string
CharNode* createStringList(const char *str) {
    CharNode *head = NULL;
    CharNode *tail = NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        CharNode *newNode = (CharNode *)malloc(sizeof(CharNode));
        //cek malloc malloc berhasil atau ge
        newNode->data = str[i];
        newNode->next = NULL;
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

//fungsi untuk memvalidasi nama(hanya huruf dan spasi)
bool isValidName(const char *input) {
    while (*input) {
        if (!isalpha(*input) && *input != ' ') {
            return false; 
        }
        input++;
    }
    return true;
}

// Fungsi untuk membaca input dan menyimpannya dalam linked list
CharNode* readInput() {
    CharNode *head = NULL;
    CharNode *tail = NULL;
    char ch;
    char buffer[100];
    int index = 0;


    while ((ch = getchar()) != '\n' && ch != EOF) {
        buffer [index++] = ch;
    }
    buffer[index] = '\0';
    if (!isValidName(buffer)) {
        printf("Error: Nama hanya boleh mengandung huruf dan spasi\n");
        return NULL;
    }

    for(int i = 0; buffer[i] != '\0'; i++){
        CharNode *newNode = (CharNode *)malloc(sizeof(CharNode));
        if(newNode == NULL){
            printf("ERRor: gagal mengalokasikan memori\n");
        //return;
        }
        newNode->data = buffer[i];
        newNode->next = NULL;
        
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Fungsi untuk mencetak linked list string
void printStringList(CharNode *head) {
    CharNode *current = head;
    while (current != NULL) {
        printf("%c", current->data);
        current = current->next;
    }
}

//fungsi untuk mencetak linked list string
void charListToString(CharNode *head, char *str, int maxLength){
    int i = 0;
    CharNode *current = head;
    while (current != NULL && i < maxLength -1) {
        str[i] = current->data;
        current = current->next;
        i++;
    }
//tambahkan spasi jika panjang string kurang dari maxlength
    while(i < maxLength -1){
        str[i] = ' ';
        i++;
    }
    str[i] = '\0';

}

// Menambahkan nasabah ke antrean (Enqueue)
void enqueue(Queue *queue, CharNode *nama, CharNode *layanan) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Alokasi memori gagal\n");
        return;
    }
    newNode->data.nama = nama; // buat linked list untuk nama
    newNode->data.layanan = layanan; // buat linked list untuk layanan
    newNode->next = NULL;

    if (isQueueEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
