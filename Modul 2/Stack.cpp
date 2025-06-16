#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define MAX 20

using namespace std;

struct Tumpuk_Struct {
    int data[MAX];
    int atas;     
};

Tumpuk_Struct Tumpuk;

void inisialisasi() {
    Tumpuk.atas = -1;
}

int kosong() {
    if (Tumpuk.atas == -1) {
        return 1; 
    } else {
        return 0;
    }
}

int penuh() {
    if (Tumpuk.atas == MAX - 1) {
        return 1;
    } else {
        return 0;
    }
}

void input(int data) {
    if (kosong() == 1) { 
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " Masuk Ke Stack";
    } else if (penuh() == 0) { 
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " Masuk Ke Stack";
    } else { 
        cout << "Tumpukan Penuh (Kapasitas: " << MAX << ")"; 
    }
    cout << endl;
}

void hapus() {
    if (kosong() == 0) {
        cout << "Data Teratas Sudah Terambil";
        Tumpuk.atas--; 
    } else { 
        cout << "Data Kosong";
    }
    cout << endl; 
}

void tampil() {
    if (kosong() == 0) {
        cout << "Isi Tumpukan (Max: " << MAX << "):" << endl;
        for (int i = Tumpuk.atas; i >= 0; i--) {
            cout << "Tumpukan Ke " << i << " = " << Tumpuk.data[i] << endl;
        }
    } else {
        cout << "Tumpukan Kosong";
        cout << endl;
    }
}

void bersih() {
    Tumpuk.atas = -1;
    cout << "Tumpukan Kosong !";
    cout << endl;
}

int main(){
    int pilihan, data;
    inisialisasi();

    do {
        cout << "\n=== PROGRAM STACK (" << MAX << ") ===" << endl;
        cout << "1. Input Data (Push)" << endl;
        cout << "2. Hapus Data (Pop)" << endl;
        cout << "3. Tampilkan Isi Stack" << endl;
        cout << "4. Kosongkan Stack (Bersih)" << endl;
        cout << "5. Cek Kondisi (Kosong/Penuh)" << endl;
        cout << "6. Keluar" << endl;
        cout << "Masukkan Pilihan: ";
        cin >> pilihan;

        if(cin.fail()){
             cout << "Input tidak valid, harus angka." << endl;
             cin.clear(); 
             cin.ignore(10000, '\n'); 
             pilihan = 0; 
             cout << "\nTekan tombol apa saja untuk lanjut..."; getch(); system("cls");
             continue; 
        }

        switch (pilihan) {
            case 1:
                cout << "Masukkan data (integer) untuk di-input: ";
                cin >> data;
                if(cin.fail()){
                     cout << "Input data tidak valid, harus angka." << endl;
                     cin.clear(); cin.ignore(10000, '\n');
                 } else {
                    input(data); 
                 }
                break;
            case 2:
                hapus(); 
                break;
            case 3:
                tampil(); 
                break;
            case 4:
                bersih();
                break;
            case 5:
                cout << "Status Stack: ";
                if (kosong() == 1) {
                    cout << "Kosong.";
                } else if (penuh() == 1) {
                    cout << "Penuh.";
                } else {
                    cout << "Terisi (tidak penuh).";
                }
                cout << " (Top = " << Tumpuk.atas << ")" << endl;
                break;
            case 6:
                cout << "Terima kasih! Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }

        if (pilihan != 6) {
            cout << "\nTekan tombol apa saja untuk lanjut...";
            getch(); 
            system("cls"); 
        }

    } while (pilihan != 6);

    return 0;
}