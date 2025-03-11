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
