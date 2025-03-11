#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "header.h"

// Fungsi main
int main() {
    Queue antreanNasabah;
    Stack riwayatTransaksi;
    initializeQueue(&antreanNasabah);
    initializeStack(&riwayatTransaksi);

    int pilihan;
    char input[100]; //buffer menyimpan input pengguna
    do {
        printf("\n***SELAMAT DATANG DI SISTEM ANTREAN BANK***\n");
        printf("\n+----------------------------------------+\n");
        printf("|            SISTEM ANTREAN BANK         |\n");
        printf("+----------------------------------------+\n");
        printf("| 1. Tambah Nasabah ke Antrean           |\n");
        printf("| 2. Proses Nasabah                      |\n");
        printf("| 3. Tampilkan Antrean Saat Ini          |\n");
        printf("| 4. Tampilkan Riwayat Layanan           |\n");
        printf("| 5. Batalkan Transaksi Terakhir (Undo)  |\n");
        printf("| 6. Keluar                              |\n"); 
        printf("+----------------------------------------+\n");
        printf(" >> Pilihan Anda: ");

        //Membaca input sebagai string
        if (fgets(input, sizeof(input), stdin) != NULL) {
            //Menghapus newline dari input
            input[strcspn(input, "\n")] = '\0';

            //memeriksa apakah input adalah angka
            if (is_valid_number(input)) {
                pilihan = atoi(input); //mengubah string ke integer
            }else{
                printf("Input tidak valid. Harap masukkan angka antara 1 hingga 6\n");
                continue; //lanjut ke iterasi berikutnya
            }
        }else {
            printf("Error membaca input\n");
            continue;
        }
       
        switch (pilihan) {
            case 1: {
                printf("\nMasukkan nama nasabah: ");
                CharNode *nama = readInput(); // membaca nama sebagai linked list
                if (nama == NULL){
                    continue;
                }
                printf("Pilih jenis layanan:\n");
                printf(" 1. Setor Tunai\n");
                printf(" 2. Tarik Tunai\n");
                printf(" 3. Pembukaan Rekening\n");
                printf("Pilihan (1-3): ");
                
                int jenisLayanan;
                if (fgets(input, sizeof(input), stdin) != NULL){
                    input[strcspn(input, "\n")] = '\0'; //menghapus newline
                    
                    if(is_valid_number(input)) {
                        jenisLayanan = atoi(input);
                    }else {
                        printf("Input tidak valid. Harap masukkan angka\n");
                        freeCharList(nama); //membersihkan memori jika input tidak valid
                        continue;
                    }
                }else{
                    printf("Error membaca input\n");
                    freeCharList(nama);
                    continue;
                }

                CharNode *layanan = NULL;
                switch (jenisLayanan) {
                    case 1: 
                        layanan = createStringList("Setor Tunai");
                        break;
                    case 2: 
                        layanan = createStringList("Tarik Tunai");
                        break;
                    case 3:
                        layanan = createStringList("Pembukaan Rekening");
                        break;
                    default:
                        printf("Pilihan tidak valid\n");
                        freeCharList(nama); // Membersihkan memori jika pilihan tidak valid
                        continue;
                }

                enqueue(&antreanNasabah, nama, layanan);
                break;
            }

            case 2:
                if (isQueueEmpty(&antreanNasabah)) {
                    printf("Antrean kosong, tidak ada nasabah untuk diproses\n");    
                } else {
                    Nasabah nasabah = dequeue(&antreanNasabah);
                    push(&riwayatTransaksi, nasabah);
                    printf(" Layanan selesai diproses dan dipindahkan ke riwayat\n");
                }
                break;

            case 3:
                displayQueue(&antreanNasabah);
                break;

            case 4:
                displayStack(&riwayatTransaksi);
                break;

            case 5:
                undo(&antreanNasabah, &riwayatTransaksi);
                break;
            
            case 6:
                printf("\nTerima kasih telah menggunakan sistem antrean bank\n");
                break;

            default:
                printf("Pilihan tidak valid. Harap masukkan angka antara 1 hingga 3\n");
        }   
    } while (pilihan != 6);

    // Membersihkan memori yang tersisa
    while (!isQueueEmpty(&antreanNasabah)) {
        Nasabah nasabah= dequeue(&antreanNasabah);
        freeCharList(nasabah.nama);
        freeCharList(nasabah.layanan);
    }

    while (!isStackEmpty(&riwayatTransaksi)) {
        Nasabah nasabah = pop(&riwayatTransaksi);
        freeCharList(nasabah.nama);
        freeCharList(nasabah.layanan);
    }

    return 0;   
}

