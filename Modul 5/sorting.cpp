#include <iostream>
#include <functional>
#include <chrono>
#include <string>
#include <algorithm>

using namespace std;

string name = "RachelWinaYuda"; 
string id = "2410817220030";

void printString(const string& s) {
    for (char c : s) cout << c;
    cout << endl;
}

void timeSort(const function<void()>& sortFunc, const string& sortName) {
    auto start = chrono::high_resolution_clock::now();
    sortFunc();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << fixed;
    cout.precision(10); 
    cout << sortName << " took " << duration.count() << " seconds\n";
}

void insertionSort(){
    for (int i = 1; i < name.length(); i++) {
        char key = name[i];
        int j = i - 1;
        while (j >= 0 && name[j] > key) {
            name[j + 1] = name[j];
            j--;
        }
        name[j + 1] = key;
    }
}

void merge(string& s, int l, int m, int r) {
    string left = s.substr(l, m - l + 1);
    string right = s.substr(m + 1, r - m);
    int i = 0, j = 0, k = l;

    while (i < left.length() && j < right.length()) {
        if (left[i] <= right[j]) s[k++] = left[i++];
        else s[k++] = right[j++];
    }
    while (i < left.length()) s[k++] = left[i++];
    while (j < right.length()) s[k++] = right[j++];
}

void mergeSortHelper(string& s, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSortHelper(s, l, m);
        mergeSortHelper(s, m + 1, r);
        merge(s, l, m, r);
    }
}

void mergeSort(){
    mergeSortHelper(name, 0, name.length() - 1);
}

void shellSort(){
    int n = name.length();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            char temp = name[i];
            int j;
            for (j = i; j >= gap && name[j - gap] > temp; j -= gap) {
                name[j] = name[j - gap];
            }
            name[j] = temp;
        }
    }
}

void bubleSort(){
    for (int i = 0; i < id.length() - 1; i++) {
        for (int j = 0; j < id.length() - i - 1; j++) {
            if (id[j] > id[j + 1]) {
                swap(id[j], id[j + 1]);
            }
        }
    }
}

void quickSortHelper(string& s, int low, int high) {
    if (low < high) {
        char pivot = s[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (s[j] < pivot) {
                i++;
                swap(s[i], s[j]);
            }
        }
        swap(s[i + 1], s[high]);
        int pi = i + 1;
        quickSortHelper(s, low, pi - 1);
        quickSortHelper(s, pi + 1, high);
    }
}

void quickSort(){
    quickSortHelper(id, 0, id.length() - 1);
}

void selectionSort(){
    int n = id.length();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (id[j] < id[minIdx])
                minIdx = j;
        }
        swap(id[i], id[minIdx]);
    }
}

void tampilkanMenu() {
    cout << "+===========================+\n";
    cout << "| Sorting Algorithm         |\n";
    cout << "+===========================+\n";
    cout << "| 1. Insertion Sort         |\n";
    cout << "| 2. Merge Sort             |\n";
    cout << "| 3. Shell Sort             |\n";
    cout << "| 4. Bubble Sort            |\n";
    cout << "| 5. Quick Sort             |\n";
    cout << "| 6. Selection Sort         |\n";
    cout << "| 7. Exit                   |\n";
    cout << "+===========================+\n";
    cout << "Masukkan Pilihan: ";
}

int main(){
    int pilihan;
    do {
        name = "RachelWinaYuda";
        id = "2410817220030";

        tampilkanMenu();
        cin >> pilihan;

        if (pilihan >= 1 && pilihan <= 3) {
            cout << "Data Sebelum Diurutkan: " << name << endl;

            if (pilihan == 1) timeSort(insertionSort, "Insertion Sort");
            else if (pilihan == 2) timeSort(mergeSort, "Merge Sort");
            else if (pilihan == 3) timeSort(shellSort, "Shell Sort");

            cout << "Data Setelah Diurutkan: ";
            printString(name);
        }
        else if (pilihan >= 4 && pilihan <= 6) {
            cout << "Data Sebelum Diurutkan: " << id << endl;

            if (pilihan == 4) timeSort(bubleSort, "Bubble Sort");
            else if (pilihan == 5) timeSort(quickSort, "Quick Sort");
            else if (pilihan == 6) timeSort(selectionSort, "Selection Sort");

            cout << "Data Setelah Diurutkan: ";
            printString(id);
        }
        else if (pilihan == 7) {
            cout << "Terima kasih!\n";
        }
        else {
            cout << "Pilihan tidak valid!\n";
        }

        if (pilihan != 7) {
            cout << "\nPress any key to continue...\n";
            cin.ignore(); cin.get();
            system("cls");
        }

    } while (pilihan != 7);

    return 0;
}