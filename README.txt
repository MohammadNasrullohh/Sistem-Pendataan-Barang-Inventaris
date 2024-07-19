Sistem Pendataan Barang Inventaris

Program ini merupakan sistem pendataan barang inventaris yang memungkinkan pengguna untuk menambah, mencari, mengupdate, dan menghapus barang dari inventaris. Data barang disimpan dalam file `data.txt`.

Fitur

1. Tambah Barang
   - Menambah barang baru ke inventaris dengan ID, nama, kategori, dan jumlah stok.
   
2. Cari Barang
   - Mencari barang berdasarkan nama atau kategori.
   
3. Update Stok Barang
   - Mengupdate jumlah stok barang yang ada di inventaris.
   
4. Hapus Barang
   - Menghapus barang dari inventaris berdasarkan ID.

Cara Penggunaan

Menjalankan Program

1. Pastikan Anda memiliki kompiler C++.
2. Jalankan program

Menu Utama
1. Tambah Barang: Masukkan ID, nama, kategori, dan jumlah stok barang.
2. Cari Barang: Masukkan keyword nama atau kategori untuk mencari barang.
3. Update Stok Barang: Masukkan ID barang dan jumlah stok baru.
4. Hapus Barang: Masukkan ID barang yang akan dihapus.
5. Keluar: Keluar dari program.

Struktur Kode
struct Barang: Struktur untuk menyimpan data barang.
vector<Barang> inventaris: Daftar barang inventaris.
void simpanKeFile(): Fungsi untuk menyimpan data inventaris ke file.
void muatDariFile(): Fungsi untuk memuat data inventaris dari file.
bool idAtauNamaBarangAda(int id, const string& nama): Fungsi untuk memeriksa apakah ID atau nama barang sudah ada.
void tambahBarang(): Fungsi untuk menambah barang baru ke inventaris.
void tampilkanBarang(const Barang& barang): Fungsi untuk menampilkan data barang.
void cariBarang(): Fungsi untuk mencari barang berdasarkan nama atau kategori.
void updateStok(): Fungsi untuk mengupdate stok barang.
void hapusBarang(): Fungsi untuk menghapus barang dari inventaris.
void menu(): Fungsi untuk menampilkan menu utama dan menangani input pengguna.

Penyimpanan Data
Data barang disimpan dalam file data.txt dengan format berikut:
==============================================
id: [ID Barang]
nama: [Nama Barang]
kategori: [Kategori Barang]
stock: [Jumlah Stok Barang]
==============================================

Contoh
Berikut adalah contoh output saat program dijalankan:
Sistem Pendataan Barang Inventaris
1. Tambah Barang
2. Cari Barang
3. Update Stok Barang
4. Hapus Barang
5. Keluar
Pilih menu: 1
Masukkan ID barang (angka): 1
Masukkan nama barang: Keyboard
Masukkan kategori barang: Elektronik
Masukkan jumlah stok barang: 10
Barang berhasil ditambahkan!
