#include <iostream>
#include <string>

using namespace std;

// Menentukan kapasitas maksimal antrian
const int MAX_ANTRIAN = 5;

// Array untuk menyimpan nama pelanggan dalam antrian
string antrian[MAX_ANTRIAN];
// Penanda untuk menunjukkan posisi akhir dari antrian
int tail = 0;

// Fungsi untuk mengecek apakah antrian sudah penuh
bool isFull() {
    return tail >= MAX_ANTRIAN;
}

// Fungsi untuk mengecek apakah antrian kosong
bool isEmpty() {
    return tail == 0;
}

// Fungsi untuk menambahkan pesanan baru ke akhir antrian (Enqueue)
void tambahPesanan() {
    if (isFull()) {
        cout << "\nAntrian sudah penuh, mohon tunggu sebentar." << endl;
    } else {
        cout << "Masukkan nama pelanggan: ";
        cin >> antrian[tail];
        cout << "Pesanan untuk '" << antrian[tail] << "' telah ditambahkan ke antrian." << endl;
        tail++; // Geser posisi akhir antrian
    }
}

// Fungsi untuk memanggil/melayani pesanan dari depan antrian (Dequeue)
void panggilPesanan() {
    if (isEmpty()) {
        cout << "\nTidak ada pesanan dalam antrian." << endl;
    } else {
        cout << "\nMemanggil pesanan untuk: " << antrian[0] << endl;
        // Geser semua elemen antrian ke depan
        for (int i = 0; i < tail - 1; i++) {
            antrian[i] = antrian[i + 1];
        }
        tail--; // Kurangi jumlah antrian
    }
}

// Fungsi untuk menampilkan semua pesanan yang ada dalam antrian
void lihatAntrian() {
    if (isEmpty()) {
        cout << "\nTidak ada pesanan dalam antrian." << endl;
    } else {
        cout << "\n===== Daftar Antrian Saat Ini =====" << endl;
        for (int i = 0; i < tail; i++) {
            cout << i + 1 << ". " << antrian[i] << endl;
        }
        cout << "==================================" << endl;
    }
}

int main() {
    int pilihan;

    do {
        cout << "\n===== Sistem Antrian Kafe Sederhana =====" << endl;
        cout << "1. Tambah Pesanan" << endl;
        cout << "2. Panggil Pesanan" << endl;
        cout << "3. Lihat Antrian" << endl;
        cout << "4. Keluar" << endl;
        cout << "=======================================" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            tambahPesanan();
        } else if (pilihan == 2) {
            panggilPesanan();
        } else if (pilihan == 3) {
            lihatAntrian();
        } else if (pilihan == 4) {
            cout << "\nTerima kasih telah menggunakan sistem ini." << endl;
        } else {
            cout << "\nPilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 4);

    return 0;
}