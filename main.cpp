#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <limits>

using namespace std;

struct Barang {
    int id; // ID barang sebagai angka
    string nama;
    string kategori;
    int stok;
};

vector<Barang> inventaris;

void simpanKeFile() {
    ofstream file("data.txt");
    if (file.is_open()) {
        for (const auto& barang : inventaris) {
            file << "==============================================" << '\n';
            file << "id: " << barang.id << '\n';
            file << "nama: " << barang.nama << '\n';
            file << "kategori: " << barang.kategori << '\n';
            file << "stock: " << barang.stok << '\n';
            file << "==============================================" << '\n';
        }
        file.close();
    } else {
        cout << "Tidak dapat membuka file untuk menyimpan data." << endl;
    }
}

void muatDariFile() {
    ifstream file("data.txt");
    if (file.is_open()) {
        string line;
        Barang barang;
        while (getline(file, line)) {
            if (line == "==============================================") {
                if (file >> ws, getline(file, line) && line.substr(0, 4) == "id: ") {
                    barang.id = stoi(line.substr(4));
                }
                if (getline(file, line) && line.substr(0, 6) == "nama: ") {
                    barang.nama = line.substr(6);
                }
                if (getline(file, line) && line.substr(0, 10) == "kategori: ") {
                    barang.kategori = line.substr(10);
                }
                if (getline(file, line) && line.substr(0, 7) == "stock: ") {
                    barang.stok = stoi(line.substr(7));
                }
                inventaris.push_back(barang);
                getline(file, line); // Baca penutup "=============================================="
            }
        }
        file.close();
    } else {
        cout << "Tidak dapat membuka file untuk memuat data." << endl;
    }
}

bool idAtauNamaBarangAda(int id, const string& nama) {
    for (const auto& barang : inventaris) {
        if (barang.id == id || barang.nama == nama) {
            return true;
        }
    }
    return false;
}

void tambahBarang() {
    Barang barang;
    cout << "Masukkan ID barang (angka): ";
    while (!(cin >> barang.id)) {
        cout << "ID harus berupa angka. Coba lagi: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(); // Membersihkan buffer input

    cout << "Masukkan nama barang: ";
    getline(cin, barang.nama);

    if (idAtauNamaBarangAda(barang.id, barang.nama)) {
        cout << "Barang dengan ID atau nama tersebut sudah ada. Tidak bisa menambahkan barang yang sama." << endl;
        return;
    }

    cout << "Masukkan kategori barang: ";
    getline(cin, barang.kategori);

    cout << "Masukkan jumlah stok barang: ";
    while (!(cin >> barang.stok)) {
        cout << "Stok harus berupa angka. Coba lagi: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(); // Membersihkan buffer input

    inventaris.push_back(barang);
    cout << "Barang berhasil ditambahkan!" << endl;
    simpanKeFile(); // Simpan data ke file setelah menambahkan barang
}

void tampilkanBarang(const Barang& barang) {
    cout << "ID: " << barang.id << endl;
    cout << "Nama: " << barang.nama << endl;
    cout << "Kategori: " << barang.kategori << endl;
    cout << "Stok: " << barang.stok << endl;
    cout << "-------------------------" << endl;
}

void cariBarang() {
    string keyword;
    cout << "Masukkan nama atau kategori barang yang dicari: ";
    cin.ignore(); // Membersihkan buffer input
    getline(cin, keyword);

    bool ditemukan = false;
    for (const auto& barang : inventaris) {
        if (barang.nama.find(keyword) != string::npos || barang.kategori.find(keyword) != string::npos) {
            tampilkanBarang(barang);
            ditemukan = true;
        }
    }

    if (!ditemukan) {
        cout << "Barang belum ditambahkan/tidak ada." << endl;
    }
}

void updateStok() {
    int id;
    cout << "Masukkan ID barang yang akan diupdate: ";
    while (!(cin >> id)) {
        cout << "ID harus berupa angka. Coba lagi: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (auto& barang : inventaris) {
        if (barang.id == id) {
            cout << "Masukkan jumlah stok baru: ";
            while (!(cin >> barang.stok)) {
                cout << "Stok harus berupa angka. Coba lagi: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore(); // Membersihkan buffer input
            cout << "Stok barang berhasil diupdate!" << endl;
            simpanKeFile(); // Simpan data ke file setelah mengupdate stok
            return;
        }
    }

    cout << "Barang dengan ID tersebut tidak ditemukan." << endl;
}

void hapusBarang() {
    int id;
    cout << "Masukkan ID barang yang akan dihapus: ";
    while (!(cin >> id)) {
        cout << "ID harus berupa angka. Coba lagi: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    auto it = remove_if(inventaris.begin(), inventaris.end(), [id](Barang barang) {
        return barang.id == id;
    });

    if (it != inventaris.end()) {
        inventaris.erase(it, inventaris.end());
        cout << "Barang berhasil dihapus!" << endl;
        simpanKeFile(); // Simpan data ke file setelah menghapus barang
    } else {
        cout << "Barang dengan ID tersebut tidak ditemukan." << endl;
    }
}

void menu() {
    muatDariFile(); // Memuat data dari file saat program dimulai
    int pilihan;
    do {
        cout << "Sistem Pendataan Barang Inventaris" << endl;
        cout << "1. Tambah Barang" << endl;
        cout << "2. Cari Barang" << endl;
        cout << "3. Update Stok Barang" << endl;
        cout << "4. Hapus Barang" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        while (!(cin >> pilihan)) {
            cout << "Pilihan tidak valid. Silakan coba lagi: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(); // Membersihkan buffer input

        switch (pilihan) {
            case 1:
                tambahBarang();
                break;
            case 2:
                cariBarang();
                break;
            case 3:
                updateStok();
                break;
            case 4:
                hapusBarang();
                break;
            case 5:
                cout << "Terima kasih telah menggunakan program ini." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 5);
}

int main() {
    menu();
    return 0;
}
