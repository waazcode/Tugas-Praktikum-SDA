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



