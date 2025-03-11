#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Struktur untuk menyimpan satu karakter dalam linked list 
typedef struct CharNode {
    char data;
    struct CharNode *next;
} CharNode;

// Struktur untuk menyimpan data nasabah
typedef struct Nasabah {
    CharNode *nama; // linked list untuk nama 
    CharNode *layanan; // linked list untuk layanan
} Nasabah;

// Struktur Node untuk Queue
typedef struct Node {
    Nasabah data;
    struct Node *next;
} Node;

// Struktur Queue
typedef struct Queue {
    Node *front; // pointer ke elemen depan antrean
    Node *rear; // pointer ke elemen belakang antrean
    int size; // ukuran antrean
} Queue;

// Struktur Node untuk Stack
typedef struct StackNode {
    Nasabah data;
    struct StackNode *next;
} StackNode;

// Struktur Stack
typedef struct Stack {
    StackNode *top; // pointer ke elemen teratas stack
    unsigned size; // ukuran Stack
} Stack;

// Inisialisasi Queue
void initializeQueue(Queue *queue);

// Inisialisai Stack
void initializeStack(Stack *stack);
// Memeriksa apakah Queue kosong 
bool isQueueEmpty(Queue *queue);

// Memeriksa apakah Stack kosong
bool isStackEmpty(Stack *stack);

// Fungsi untuk membuat linked list dari string
CharNode* createStringList(const char *str); 

//fungsi untuk memvalidasi nama(hanya huruf dan spasi)
bool isValidName(const char *input);

// Fungsi untuk membaca input dan menyimpannya dalam linked list
CharNode* readInput();

//fungsi untuk mencetak linked list string
void charListToString(CharNode *head, char *str, int maxLength);

// Menambahkan nasabah ke antrean (Enqueue)
void enqueue(Queue *queue, CharNode *nama, CharNode *layanan);

// Menambah nasabah ke riwayat transaksi (Push)
void push(Stack *stack, Nasabah nasabah); 

// Menghapus nasabah ke riwayat transakasi (Pop)
Nasabah pop(Stack *stack);

// Menampilkan seluruh nasabah dalam antrean
void displayQueue(Queue *queue);

// Menampilkan seluruh riwayat transaksi
void displayStack(Stack *stack);

// Membatalkan transaksi terakhir (undo)
void undo(Queue *queue, Stack *stack);

// Fungsi untuk memeriksa apakah input menu valid (hanya angka)
int is_valid_number(const char *input);

// Fungsi untuk memfreekan seluruh linked list CharNode
void freeCharList(CharNode *head); 

Nasabah dequeue(Queue *queue);

#endif
