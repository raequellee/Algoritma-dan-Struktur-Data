#include <iostream>
#include <conio.h>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;


void sequentialSearch(const vector<int> &nums, int target){
    bool found = false;
    int count = 0;
    vector<int> found_indices;

    cout << "Hasil Sequential Search:" << endl;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == target) {
            found = true;
            count++;
            found_indices.push_back(i);
        }
    }

    if (found) {
        cout << "Angka " << target << " ditemukan sebanyak " << count << " kali pada indeks: ";
        for (int i = 0; i < found_indices.size(); ++i) {
            cout << found_indices[i] << (i == found_indices.size() - 1 ? "" : ", ");
        }
        cout << endl;
    } else {
        cout << "Angka " << target << " tidak ditemukan dalam daftar." << endl;
    }
}

void binarySearch(const vector<int> &nums, int target){

    cout << "Hasil Binary Search (pada data yang sudah diurutkan):" << endl;
    int left = 0;
    int right = nums.size() - 1;
    bool found = false;
    int found_index = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2; 
        if (nums[mid] == target) {
            found = true;
            found_index = mid;
            break; 
        } else if (nums[mid] < target) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }

    if (found) {
        cout << "Angka " << target << " ditemukan pada indeks " << found_index << "." << endl;
    } else {
        cout << "Angka " << target << " tidak ditemukan dalam daftar." << endl;
    }
}

/// use this to clear screen, change if necessary
void clearScreen(){
#ifdef _WIN32
    system("cls");
#else
    system("clear"); 
#endif
}

// use this to  print your answer
void explain(){
    clearScreen();
    cout << "===================================================================" << endl;
    cout << "   Perbedaan, Kelebihan, dan Kekurangan Sequential vs Binary Search" << endl;
    cout << "===================================================================" << endl;
    cout << endl;

    cout << "--- Sequential Searching ---" << endl;
    cout << "Sequential Search, atau pencarian berurutan, adalah metode pencarian yang paling intuitif. Cara" << endl;
    cout << "kerjanya sangat sederhana: ia akan memeriksa setiap elemen dalam kumpulan data satu demi satu," << endl;
    cout << "dimulai dari elemen paling awal. Jika elemen yang dicari cocok dengan elemen yang sedang" << endl; 
    cout << "diperiksa, maka pencarian dianggap berhasil dan posisinya diketahui. Namun, jika hingga elemen" << endl; 
    cout << "terakhir elemen yang dicari tidak juga ditemukan, maka pencarian dinyatakan gagal. Salah satu" << endl;
    cout << "aspek penting dari Sequential Search adalah ia tidak menuntut data harus dalam keadaan terurut." << endl;
    cout << "Ini berarti ia bisa langsung digunakan pada data yang acak sekalipun." << endl;
    cout << endl;

    cout << "Kelebihan utama dari Sequential Search terletak pada kesederhanaannya, baik dalam pemahaman" << endl;
    cout << "maupun implementasi. Ia juga fleksibel karena bisa diterapkan pada berbagai struktur data" << endl;
    cout << "linier tanpa perlu repot-repot mengurutkan data terlebih dahulu. Untuk kumpulan data yang" << endl;
    cout << "jumlahnya sedikit, Sequential Search bisa jadi cukup efisien. Namun, kekurangannya menjadi" << endl;
    cout << "sangat terasa ketika berhadapan dengan data dalam jumlah besar. Karena harus memeriksa satu" << endl;
    cout << "per satu, waktu pencariannya bisa menjadi sangat lama, terutama jika data yang dicari berada" << endl;
    cout << "di akhir atau bahkan tidak ada sama sekali." << endl;
    cout << endl;

    cout << "\n" << endl;
    cout << "--- Binary Searching ---" << endl;
    cout << "Binary Search, atau pencarian biner, menawarkan pendekatan yang jauh lebih efisien, namun" << endl;
    cout << "dengan syarat. Metode ini bekerja berdasarkan prinsip 'bagi dan taklukkan' (divide and conquer)." << endl;
    cout << "Syarat utamanya adalah data HARUS sudah dalam keadaan terurut, baik secara menaik maupun" << endl;
    cout << "menurun. Prosesnya dimulai dengan mengambil elemen tengah dari kumpulan data. Elemen tengah" << endl;
    cout << "ini kemudian dibandingkan dengan elemen yang dicari. Jika cocok, pencarian selesai. Jika" << endl;
    cout << "elemen yang dicari lebih kecil, maka Binary Search akan mengabaikan setengah bagian kanan data" << endl;
    cout << "dan melanjutkan pencarian hanya pada setengah bagian kiri. Sebaliknya, jika elemen yang dicari" << endl;
    cout << "lebih besar, setengah bagian kiri data akan diabaikan, dan pencarian fokus pada setengah bagian" << endl;
    cout << "kanan. Proses membagi dua dan membandingkan ini terus berlanjut pada bagian data yang semakin" << endl;
    cout << "kecil hingga elemen ditemukan atau hingga tidak ada lagi bagian data yang tersisa untuk dicari." << endl;
    cout << endl;

    cout << "Keunggulan paling signifikan dari Binary Search adalah kecepatannya yang luar biasa untuk data" << endl;
    cout << "besar. Setiap langkahnya mampu mengeliminasi setengah dari sisa data yang perlu diperiksa," << endl;
    cout << "membuatnya jauh lebih cepat daripada Sequential Search. Namun, kelemahan utamanya adalah" << endl;
    cout << "keharusan data yang sudah terurut. Jika data awal belum terurut, maka ada biaya tambahan untuk" << endl;
    cout << "proses pengurutan, yang juga memakan waktu. Untuk data yang sangat sedikit, keunggulan kecepatan" << endl;
    cout << "Binary Search mungkin tidak terlalu terasa. Selain itu, Binary Search kurang cocok untuk struktur" << endl;
    cout << "data seperti linked list karena kesulitan mengakses elemen tengah secara efisien. Implementasinya" << endl;
    cout << "juga sedikit lebih kompleks dibandingkan Sequential Search." << endl;
    cout << endl;

    cout << "\n" << endl;
    cout << "Secara ringkas, pilihlah Sequential Search jika Anda berhadapan dengan data yang jumlahnya" << endl;
    cout << "sedikit, atau jika data tidak terurut dan biaya untuk mengurutkannya dianggap terlalu besar." << endl;
    cout << "Kesederhanaan implementasi juga bisa menjadi pertimbangan. Sebaliknya, Binary Search adalah" << endl;
    cout << "pilihan yang sangat baik ketika Anda memiliki data dalam jumlah besar, data tersebut sudah" << endl;
    cout << "terurut (atau bisa diurutkan sekali untuk banyak pencarian), dan kecepatan pencarian" << endl;
    cout << "menjadi prioritas utama Anda." << endl;
    cout << endl;
}

void printVector(const string& message, const vector<int>& nums) {
    cout << message << endl;
    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
        if ((i + 1) % 10 == 0 || i == nums.size() - 1) {
            cout << endl;
        }
    }
    if (nums.empty() || (nums.size() % 10 != 0 && nums.size() < 10 && nums.size() > 0) ) {
    } else if (nums.size() % 10 != 0 && !nums.empty()){
        cout << endl;
    }
    cout << "-----------------------------------" << endl;
}

int main() {
    int opt = 0, target;
    do {
        cout << "Pilih menu" << endl;
        cout << "1. Sequential Searching" << endl;
        cout << "2. Binary Searching" << endl;
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!" << endl;
        cout << "4. Exit" << endl;
        cout << "Pilih: ";
        cin >> opt;

        if (cin.fail()) {
            cout << "Input tidak valid. Masukkan angka." << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            opt = 0;
        } 

        switch (opt) {
            case 1: {
                clearScreen();
                vector<int> nums (100);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 50);

                for (auto &val: nums) {
                    val = (dist(rng));
                }

                printVector("Daftar angka acak (Sequential Search):", nums);

                cout << "Masukkan angka yang ingin dicari: "; cin >> target;
                if (cin.fail()) {
                     cout << "Input target tidak valid." << endl;
                     cin.clear();
                     cin.ignore(numeric_limits<streamsize>::max(), '\n');
                     break;
                }
                sequentialSearch(nums, target);
                break;
            }

            case 2: {
                clearScreen();
                int size;
                cout << "Masukkan ukuran vector: ";
                cin >> size;

                if (cin.fail() || size <= 0) {
                    cout << "Ukuran vector tidak valid." << endl;
                    if(cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    break;
                }

                vector<int> nums(size);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 100);

                for (auto &val: nums) {
                    val = (dist(rng));
                }

                printVector("Daftar angka acak sebelum diurutkan (Binary Search):", nums);

                sort(nums.begin(), nums.end());
                printVector("Daftar angka setelah diurutkan (Binary Search):", nums);

                cout << "Masukkan angka yang ingin dicari: "; cin >> target;
                if (cin.fail()) {
                     cout << "Input target tidak valid." << endl;
                     cin.clear();
                     cin.ignore(numeric_limits<streamsize>::max(), '\n');
                     break;
                }
                binarySearch(nums, target);
                break;
            }

            case 3:
                clearScreen();
                explain();
                break;

            case 4:
                clearScreen();
                cout << "\nTERIMA KASIH\n";
                cout << "Programme was made by Rachel (2410817220030)" << endl;
                break;

            default:
                if (opt != 0) {
                    cout << "Opsi tidak terdefinisi, mohon masukkan ulang opsi" << endl;
                }
                break;
        }

        if (opt != 4) {
            cout << "\nTekan sembarang tombol untuk melanjutkan...";
            getch();
            clearScreen();
        }

    } while (opt != 4);

    return 0;
}