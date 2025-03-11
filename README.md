# Tugas-Praktikum-SDA

Anggota kelompok 2:
1.	Ulfa Khairina_2408107010013
2.	Fitriani_2408107010022
3.	Fawwaz Ziyadi Ilmi_2408107010021
4.	Muhammad Riskan Rajabi_2408107010110
5.	Muhammad Riyadh_2408107010015
6.	Teuku Rifqi Zeta_2408107010071

   
SISTEM ANTREAN BANK SEDERHANA

Program ini merupakan implementasi sistem antrean bank menggunakan bahasa pemrograman C dengan struktur data Queue (Linked List) untuk antrean nasabah dan Stack (Linked List) untuk riwayat layanan. Program ini menyediakan fitur untuk menambah, memproses, menampilkan antrean, melihat riwayat layanan, serta membatalkan transaksi terakhir. Sistem antrean bank ini dirancang untuk mengelola antrean nasabah secara efisien agar layanan di bank dapat berjalan lebih tertata dan cepat. Berikut adalah tujuan utama dari sistem ini:
1.	Mengelola Antrean Nasabah dengan Efisien
Sistem ini menggunakan Queue (Linked List) untuk memastikan First In, First Out (FIFO), sehingga nasabah yang datang lebih awal akan diproses lebih dulu. Mengurangi antrean fisik dan meningkatkan keteraturan dalam pelayanan.
2.	Mencatat dan Melacak Layanan yang Telah Diproses
Sistem menyimpan riwayat layanan menggunakan Stack (Linked List). Petugas bank dapat melihat daftar layanan yang sudah diproses dan melakukan Undo (Pembatalan Transaksi) jika diperlukan.
3.	Mempermudah Petugas Bank dalam Melayani Nasabah
Dengan sistem ini, petugas tidak perlu mencatat antrean secara manual. Petugas dapat menambah, memproses, dan melihat antrean dengan cepat melalui menu interaktif.
4.	Meminimalkan Kesalahan dalam Pengelolaan Antrean
Mengurangi risiko kelalaian manusia dalam mencatat urutan nasabah. Jika terjadi kesalahan dalam pemrosesan layanan, fitur Undo (Pembatalan Transaksi Terakhir) dapat digunakan untuk mengembalikan nasabah ke antrean.
5.	Meningkatkan Kepuasan Nasabah
Nasabah dapat melihat antrean yang jelas dan mengetahui urutan mereka dalam layanan. Memastikan keadilan dalam pelayanan, karena nasabah yang datang lebih awal akan diproses lebih dulu.

PENJELASAN SETIAP FILE:
1.	Header.h : File untuk mendefinisikan beberapa struktur data yang digunakan untuk mengelola elemen-elemen dalam bentuk linked list, queue, dan stack untuk aplikasi yang berhubungan dengan data nasabah.
2.	Main.c  : Fungsi main yang merupakan implementasi dari sistem antrean bank yang menggunakan struktur data queue (antrian) dan stack (tumpukan). Berikut adalah penjelasan rinci tentang fungsi ini:
initializeQueue(&antreanNasabah): Menginisialisasi antrean kosong. 
initializeStack(&riwayatTransaksi): Menginisialisasi stack kosong. 
is_valid_number(input): Memeriksa apakah input yang diberikan berupa angka. 
readInput(): Membaca input dan mengubahnya menjadi linked list untuk nama. 
createStringList(str): Membuat linked list dari string yang diberikan (untuk layanan). 
enqueue(&antreanNasabah, nama, layanan): Menambahkan nasabah ke antrean. 
dequeue(&antreanNasabah): Mengambil nasabah dari antrean. 
push(&riwayatTransaksi, nasabah): Menambahkan nasabah ke stack (untuk riwayat transaksi). 
displayQueue(&antreanNasabah): Menampilkan semua nasabah dalam antrean. 
displayStack(&riwayatTransaksi): Menampilkan riwayat transaksi dalam stack. 
undo(&antreanNasabah, &riwayatTransaksi): Membatalkan transaksi terakhir (mengembalikan nasabah ke antrean). 
freeCharList(): Membebaskan memori yang digunakan oleh linked list untuk nama dan layanan.
3.	FungsiNasabah.c : File ini berisi berbagai fungsi yang berhubungan dengan sistem antrean dan riwayat transaksi nasabah dalam sebuah bank. Fungsi-fungsi ini menggunakan struktur data seperti Queue (antrean) dan Stack (riwayat transaksi) yang didefinisikan di dalam header file sebelumnya.Berikut penjelasan masing-masing fungsinya:
initializeQueue(Queue *queue): Menginisialisasi antrean dengan front dan rear ke NULL dan ukuran menjadi 0.
initializeStack(Stack *stack): Menginisialisasi stack dengan top ke NULL dan ukuran menjadi 0.
isQueueEmpty(Queue *queue): Memeriksa apakah antrean kosong dengan mengecek apakah front adalah NULL.
isStackEmpty(Stack *stack): Memeriksa apakah stack kosong dengan mengecek apakah top adalah NULL.
createStringList(const char *str): Mengonversi string biasa menjadi linked list karakter dan mengembalikan kepala linked list.
isValidName(const char *input): Memeriksa apakah string hanya berisi huruf dan spasi, mengembalikan true jika valid.
readInput(): Membaca input nama dari pengguna, memvalidasinya, dan mengonversinya menjadi linked list karakter.
printStringList(CharNode *head): Mencetak karakter-karakter dalam linked list satu per satu hingga mencapai NULL.
charListToString(CharNode *head, char *str, int maxLength): Mengonversi linked list karakter ke dalam string dengan panjang maksimal maxLength.
enqueue(Queue *queue, CharNode *nama, CharNode *layanan): Menambahkan nasabah ke antrean dengan menyimpan nama dan layanan dalam linked list.
dequeue(Queue *queue): Menghapus nasabah dari antrean dan mengembalikan data nasabah yang ada di depan antrean.
push(Stack *stack, Nasabah nasabah): Menambahkan nasabah ke dalam stack (riwayat transaksi) dengan menambahkan node baru di atas stack.
pop(Stack *stack): Menghapus dan mengembalikan nasabah dari atas stack, serta mengurangi ukuran stack.
displayQueue(Queue *queue): Menampilkan semua nasabah dalam antrean dengan nama dan layanan yang terdaftar.
displayStack(Stack *stack): Menampilkan semua riwayat transaksi dalam stack dengan nama dan layanan yang terdaftar.
undo(Queue *queue, Stack *stack): Membatalkan transaksi terakhir dengan memindahkan nasabah dari stack kembali ke antrean.
is_valid_number(const char *input): Memeriksa apakah input hanya terdiri dari angka.
freeCharList(CharNode *head): Membebaskan memori yang digunakan oleh linked list CharNode.
4.	Makefile : File yang membantu mengelola sistem dengan banyak file sumber secara otomatis, sehingga mempermudah pengembang untuk kompilasi ulang hanya pada bagian yang berubah. Makefile ini digunakan untuk mengompilasi program dengan efisien menggunakan gcc.

INSTRUKSI KOMPILASI DAN CARA MENJALANKAN PROGRAM
1.	  Jalankan make untuk mengkompilasi dan menghasilkan file output. 
2.	  Jalankan program dengan .\main. 
3.	  Bersihkan file objek menggunakan make clean.

SCREENSHOT HASIL EKSEKUSI PROGRAM
![Image](https://github.com/user-attachments/assets/bb8029a7-ad66-4f3b-8d25-94252aa2b382)
![Image](https://github.com/user-attachments/assets/75111144-f950-4b10-84f0-051b4b595078)
![Image](https://github.com/user-attachments/assets/2f2ff94a-a89b-4ebb-bad0-e0c0fe0fe31d)
![Image](https://github.com/user-attachments/assets/a4fe65a3-d760-4d9d-b2f3-93831882874a)
![Image](https://github.com/user-attachments/assets/17c0671b-f873-4b84-bff3-83536c968eeb)
![Image](https://github.com/user-attachments/assets/a39ea1e9-bbcd-40c0-aea5-0b2c7d6f3205)
![Image](https://github.com/user-attachments/assets/5bc8c22c-ea42-4229-8106-e72b5a749a22)


