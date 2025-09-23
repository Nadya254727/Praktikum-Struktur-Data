#include <iostream>
using namespace std;

int main()
{
    int arr[5];
    double total = 0;
    cout << "Masukkan 5 angka: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
        total += arr[i];
    }

    double rata = total / 5;
    cout << "Rata-rata: " << rata << endl;

    return 0;
}

/*
Masukkan 5 angka: 3   
7
9
11
15
Rata-rata: 9
*/