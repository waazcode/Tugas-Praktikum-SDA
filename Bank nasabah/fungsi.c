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
    queue->size++;
    printf(" Nasabah ");
    printStringList(newNode->data.nama);
    printf(" berhasil ditambahkan ke antrean dengan layanan ");
    printStringList(newNode->data.layanan);
    printf("\n");
}

// Menghapus nasabah dari antrean (Dequeue)
Nasabah dequeue(Queue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Antrean kosong, tidak ada nasabah untuk diproses\n");
        Nasabah empty = {NULL, NULL};
        return empty;
    }
    Node *temp = queue->front;
    Nasabah nasabah = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    queue->size--;
    return nasabah;
}

// Menambah nasabah ke riwayat transaksi (Push)
void push(Stack *stack, Nasabah nasabah) {
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        printf("Alokasi memori gagal\n");
        return;
    }
    newNode->data = nasabah;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

// Menghapus nasabah ke riwayat transakasi (Pop)
Nasabah pop(Stack *stack) {
    if (isStackEmpty(stack)) {
        printf("Riwayat transaksi kosong\n");
        Nasabah empty = {NULL, NULL};
        return empty;
    }
    StackNode *temp = stack->top;
    Nasabah nasabah = temp->data;
    stack->top = stack->top->next;
    free(temp); // membebaskan memori stackNode
    stack->size--;
    return nasabah;
}

// Menampilkan seluruh nasabah dalam antrean
void displayQueue(Queue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Antrean kosong\n");
        return;
    }
    printf("\n+----+------------------------------------------------------+------------------------------+\n");
    printf("| No.  | Nama Nasabah                                       | Layanan                      |\n");
    printf("+------+----------------------------------------------------+------------------------------+\n");
    Node *current = queue->front;
    int count = 1;
    while (current != NULL) {
        char nama[14] = {0};
        char layanan[20] = {0};

        //konversi linked list ke string 
        charListToString(current->data.nama, nama, 14);
        charListToString(current->data.layanan, layanan, 20);

        printf("| %-4d | %-50s | %-23s      |\n", count, nama,layanan);
        current = current->next;
        count++;
    }
    printf("+------+----------------------------------------------------+------------------------------+\n");
    printf("Total nasabah dalam antrean: %d\n\n", queue->size);
}

// Menampilkan seluruh riwayat transaksi
void displayStack(Stack *stack) {
    if (isStackEmpty(stack)) {
        printf("Riwayat transaksi kosong\n");
        return;
    }
    printf("\n+----+------------------------------------------------------+------------------------------+\n");
    printf("| No.  | Nama Nasabah                                       | Layanan                      |\n");
    printf("+------+----------------------------------------------------+------------------------------+\n");
    StackNode *current = stack->top;
    int count = 1;
    while (current != NULL) {
            char nama[14] = {0};
            char layanan[20] = {0};

            charListToString(current->data.nama, nama, 14);
            charListToString(current->data.layanan, layanan, 20);
    
            printf("| %-4d | %-50s | %-23s      |\n", count, nama,layanan);
        current = current->next;
        count++;
    }
    printf("+------+----------------+------------------------------------------------------------------+\n");
    printf("Total riwayat transaksi: %d\n\n", stack->size);
}

// Membatalkan transaksi terakhir (undo)
void undo(Queue *queue, Stack *stack) {
    if (isStackEmpty(stack)) {
        printf("Tidak ada transaksi untuk dibatalkan\n");
        return;
    }
    Nasabah nasabah = pop(stack); // mengambil data nasabah terakhir dilayani
    enqueue(queue, nasabah.nama, nasabah.layanan); // mengembalikan nasabah ke antrean
    printf(" Transaksi terakhir: ");
    printStringList(nasabah.nama);
    printf(" - ");
    printStringList(nasabah.layanan);
    printf(" dibatalkan. Nasabah dikembalikan ke antrean.\n");
}

// Fungsi untuk memeriksa apakah input menu valid (hanya angka)
int is_valid_number(const char *input) {
    while (*input) {
        if (!isdigit(*input)) {
            return 0;
        }
        input++;
    }
    return 1;
}

// Fungsi untuk memfreekan seluruh linked list CharNode
void freeCharList(CharNode *head) {
    CharNode *current = head;
    while (current != NULL) {
        CharNode *temp = current;
        current = current->next;
        free(temp); // Membebaskan memori setiap node
    }
}
