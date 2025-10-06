#include <iostream>
using namespace std;

int main()
{
    const int jumlahMahasiswa = 5;
    string daftarNpm[jumlahMahasiswa] = {"2217051001", "2217051002", "2217051003", "2217051004", "2217051005"};
    string daftarNama[jumlahMahasiswa] = {"Nadya", "Citra", "Alya", "Eka", "Fara"};

    string namaYangDicari;
    bool ditemukan = false;
    int indeksKetemu = -1;

    // Meminta input dari pengguna
    cout << "Masukkan nama untuk dicari: ";
    cin >> namaYangDicari;

    // Proses pencarian sequential
    for (int i = 0; i < jumlahMahasiswa; i++)
    {
        if (daftarNama[i] == namaYangDicari)
        {
            ditemukan = true;
            indeksKetemu = i;
            break; // Hentikan pencarian jika data sudah ditemukan
        }
    }

    // Menampilkan hasil pencarian
    if (ditemukan)
    {
        cout << "\nData ditemukan!" << endl;
        cout << "NPM  : " << daftarNpm[indeksKetemu] << endl;
        cout << "Nama : " << daftarNama[indeksKetemu] << endl;
    }
    else
    {
        cout << "\nMaaf, nama '" << namaYangDicari << "' tidak ada dalam daftar." << endl;
    }

    return 0;
}



