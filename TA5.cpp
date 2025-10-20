#include <iostream>
using namespace std;

struct MahasiswaNode {
    int npm;
    MahasiswaNode* kiri;
    MahasiswaNode* kanan; 
};

MahasiswaNode* BuatSimpul(int npm_baru) {
    MahasiswaNode* simpul_baru = new MahasiswaNode;
    simpul_baru->npm = npm_baru;
    simpul_baru->kiri = nullptr;
    simpul_baru->kanan = nullptr;
    return simpul_baru;
}

MahasiswaNode* Sisip(MahasiswaNode* akar, int npm_baru) {
    if (akar == nullptr) {
        return BuatSimpul(npm_baru);
    }

    if (npm_baru < akar->npm) {
        akar->kiri = Sisip(akar->kiri, npm_baru);
    } else if (npm_baru > akar->npm) {
        akar->kanan = Sisip(akar->kanan, npm_baru);
    }
    
    return akar;
}

void TampilkanInorder(MahasiswaNode* akar) {
    if (akar != nullptr) {
        TampilkanInorder(akar->kiri);
        cout << akar->npm << " ";
        TampilkanInorder(akar->kanan);
    }
}

MahasiswaNode* Cari(MahasiswaNode* akar, int npm_cari) {
    if (akar == nullptr || akar->npm == npm_cari) {
        return akar;
    }

    if (npm_cari < akar->npm) {
        return Cari(akar->kiri, npm_cari);
    } else {
        return Cari(akar->kanan, npm_cari);
    }
}

void HapusPohon(MahasiswaNode* akar) {
    if (akar != nullptr) {
        HapusPohon(akar->kiri);
        HapusPohon(akar->kanan);
        delete akar;
    }
}

int main() {
    MahasiswaNode* dataMahasiswaAkar = nullptr;

    cout << "--- Operasi Penyisipan ---\n";
    dataMahasiswaAkar = Sisip(dataMahasiswaAkar, 100);
    dataMahasiswaAkar = Sisip(dataMahasiswaAkar, 50);
    dataMahasiswaAkar = Sisip(dataMahasiswaAkar, 15);
    dataMahasiswaAkar = Sisip(dataMahasiswaAkar, 110);
    dataMahasiswaAkar = Sisip(dataMahasiswaAkar, 115);
    dataMahasiswaAkar = Sisip(dataMahasiswaAkar, 105);
    
    cout << "Data NPM (Terurut): ";
    TampilkanInorder(dataMahasiswaAkar);
    cout << "\n\n";

    cout << "--- Operasi Pencarian ---\n";
    int cari_npm1 = 50;
    if (Cari(dataMahasiswaAkar, cari_npm1) != nullptr) {
        cout << "NPM " << cari_npm1 << " ditemukan.\n";
    } else {
        cout << "NPM " << cari_npm1 << " tidak ditemukan.\n";
    }
    
    int cari_npm2 = 10;
    if (Cari(dataMahasiswaAkar, cari_npm2) != nullptr) {
        cout << "NPM " << cari_npm2 << " ditemukan.\n";
    } else {
        cout << "NPM " << cari_npm2 << " tidak ditemukan.\n";
    }
    
    HapusPohon(dataMahasiswaAkar);
    cout << "\nProgram selesai.\n";
    
    return 0;
}