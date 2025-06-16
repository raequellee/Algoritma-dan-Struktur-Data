#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define MAX 20

using namespace std;

struct Queue {
    char data[MAX];
    int front;
    int rear;
};

Queue antrian; 

void INSERT();
void DELETE();
void CETAKANTRIAN(); 
void Inisialisasi();
void RESET();
int PIL;             
char PILIHAN[1];    
char HURUF;          

void Inisialisasi() {
    antrian.front = -1; 
    antrian.rear = -1;  
}

bool isEmpty() {
    return (antrian.front == -1 || antrian.front > antrian.rear);
}

bool isFull() {
    return (antrian.rear == MAX - 1);
}

void INSERT() {
    if (isFull()) {
        cout << "Antrian Penuh" << endl;
    } else {
        cout << "Masukkan karakter: ";
        cin >> HURUF;

        if (antrian.front == -1) {
            antrian.front = 0;
        }

        antrian.rear++; 
        antrian.data[antrian.rear] = HURUF; 
        cout << "Karakter '" << HURUF << "' berhasil dimasukkan (di Antrian " << antrian.rear + 1 << ")" << endl;
    }
}

void DELETE() {
    if (isEmpty()) {
        cout << "Antrian Kosong" << endl;
    } else {
        cout << "Karakter '" << antrian.data[antrian.front] << "' (dari Antrian " << antrian.front + 1 << ") berhasil dihapus" << endl;
        antrian.front++;

        if (antrian.front > antrian.rear) {
            cout << "(Antrian menjadi kosong setelah delete)" << endl;
            antrian.front = -1;
            antrian.rear = -1;
        }
    }
}

void CETAKANTRIAN() {
    if (isEmpty()) {
        cout << "Antrian Kosong" << endl;
    } else {
        cout << "\nIsi Queue:" << endl;
        for (int i = antrian.front; i <= antrian.rear; i++) {
            cout << "Antrian " << (i + 1) << ": " << antrian.data[i] << endl;
        }
    }
}

void RESET() {
    antrian.front = -1;
    antrian.rear = -1;
    cout << "Antrian telah direset" << endl;
}

int main(){
    Inisialisasi(); 
    do {
        system("cls"); 

        cout << "QUEUE" << endl;
        cout << "=================" << endl;
        cout << "1. INSERT" << endl;
        cout << "2. DELETE" << endl;
        cout << "3. CETAK QUEUE" << endl;
        cout << "4. RESET" << endl;
        cout << "5. QUIT" << endl;

        cout << "PILIHAN ANDA : ";
        cin >> PILIHAN; 
        PIL = atoi(PILIHAN); 

        switch (PIL) {
            case 1:
                INSERT();
                break;
            case 2:
                DELETE();
                break;
            case 3:
                CETAKANTRIAN();  
                break;
            case 4:
                RESET();
                break;
            case 5:
                cout << "\nTERIMA KASIH TELAH MENGGUNAKAN PROGRAM INI" << endl;
                break;
            default:
                cout << "\nPILIHAN TIDAK VALID (Masukkan angka 1-5)" << endl;
                break;
        }

        if (PIL != 5) {
            cout << "\nPress any key to continue..." << endl;
            getch(); 
        }
    } while (PIL != 5); 

    return 0;
}