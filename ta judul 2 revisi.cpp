#include <iostream>
using namespace std;

void tukar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void cetakArray(int array[], int ukuran) {
    int i;
    for (i = 0; i < ukuran; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    
    int n = 7;
    int data[7] = {64, 34, 25, 12, 22, 11, 90};
    
    cout << "Nilai mahasiswa yang masih acak: " << endl; 
    cetakArray(data, n);

    // Panggil fungsi bubbleSort
    int i, j;
    for (i = 0; i < n - 1; i++) {
        
        for (j = 0; j < n - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                tukar(&data[j], &data[j + 1]);
            }
        }
    }

    cout << "\nNilai mahasiswa yang sudah terurut: " << endl; 
    cetakArray(data, n);
    return 0;
}

