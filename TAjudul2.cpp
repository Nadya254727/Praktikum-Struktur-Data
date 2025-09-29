#include <iostream>
using namespace std;

void tukar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void tampilkanArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int indeks_min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[indeks_min]) {
                indeks_min = j;
            }
        }
        tukar(&arr[indeks_min], &arr[i]);
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    int data[n];

    cout << "Masukkan " << n << " angka (dipisah spasi): ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    cout << "\nData sebelum diurutkan: ";
    tampilkanArray(data, n);

    selectionSort(data, n);

    cout << "Data setelah diurutkan (Selection Sort): ";
    tampilkanArray(data, n);

    return 0;
}

