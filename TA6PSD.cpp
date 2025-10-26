#include <iostream>
using namespace std;

const int UKURAN_TABEL = 5;

struct Mahasiswa {
    int npm;      // Bertindak sebagai 'key'
    string nama;  // Bertindak sebagai 'value'
    Mahasiswa* next;
};

// Fungsi untuk inisialisasi tabel
void initTabel(Mahasiswa* tabel[]) {
    for (int i = 0; i < UKURAN_TABEL; i++) {
        tabel[i] = nullptr;
    }
}

// Menggunakan npm sebagai input
int hashFunction(int npm) {
    return npm % UKURAN_TABEL;
}

// Fungsi untuk menambah data mahasiswa (insert)
void tambahData(Mahasiswa* tabel[], int npm, string nama) {
    int index = hashFunction(npm);
    
    // Pengecekan sederhana jika NPM sudah ada (untuk update nama)
    Mahasiswa* cur = tabel[index];
    while (cur != nullptr) {
        if (cur->npm == npm) {
            cur->nama = nama; // Update nama
            return;
        }
        cur = cur->next;
    }

    // Jika NPM belum ada, buat node baru
    Mahasiswa* baru = new Mahasiswa;
    baru->npm = npm;
    baru->nama = nama;
    
    // Sisipkan di awal linked list pada index tersebut
    baru->next = tabel[index];
    tabel[index] = baru;
}

// Fungsi untuk mencari data (search)
Mahasiswa* cariData(Mahasiswa* tabel[], int npm) {
    int index = hashFunction(npm);
    Mahasiswa* cur = tabel[index];
    
    // Telusuri linked list pada index yang sesuai
    while (cur != nullptr) {
        if (cur->npm == npm) {
            return cur; // Data ditemukan
        }
        cur = cur->next;
    }
    return nullptr; // Data tidak ditemukan
}

// Fungsi untuk menampilkan isi tabel (display)
void tampilData(Mahasiswa* tabel[]) {
    cout << "\nData Mahasiswa (Hash Table):\n";
    for (int i = 0; i < UKURAN_TABEL; i++) {
        cout << "Index " << i << ": ";
        Mahasiswa* tmp = tabel[i];
        while (tmp != nullptr) {
            // Menampilkan (NPM, Nama)
            cout << "(" << tmp->npm << "," << tmp->nama << ") -> ";
            tmp = tmp->next;
        }
        cout << "NULL\n";
    }
}

int main() {
    // Buat tabel hash (pointer array)
    Mahasiswa* tabel[UKURAN_TABEL];
    
    // Inisialisasi semua isi tabel dengan nullptr
    initTabel(tabel);

    // Menambahkan beberapa data mahasiswa
    // 101 dan 106 akan berada di index yang sama (memicu collision)
    tambahData(tabel, 101, "Nadya");
    tambahData(tabel, 106, "Citra"); // Ini akan menyebabkan collision di index 1
    tambahData(tabel, 203, "Galih");
    tambahData(tabel, 404, "Dewi");

    // Tampilkan isi tabel hash
    tampilData(tabel);

    // Mencari data
    int npmCari = 106;
    Mahasiswa* hasil = cariData(tabel, npmCari);
    
    if (hasil != nullptr) {
        cout << "\nNPM " << npmCari << " ditemukan, nama = " << hasil->nama << endl;
    } else {
        cout << "\nNPM " << npmCari << " tidak ditemukan\n";
    }
    
    // Mencari data yang tidak ada
    npmCari = 999;
    hasil = cariData(tabel, npmCari);
    
    if (hasil != nullptr) {
        cout << "\nNPM " << npmCari << " ditemukan, nama = " << hasil->nama << endl;
    } else {
        cout << "\nNPM " << npmCari << " tidak ditemukan\n";
    }

    return 0;
}