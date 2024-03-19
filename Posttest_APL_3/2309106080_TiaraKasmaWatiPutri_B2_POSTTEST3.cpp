#include <iostream>
using namespace std;

string brand_baju[100] = {"Gucci", "Chanel", "Versace", "Nike", "Zara", "Celine", "Balenciaga", "Puma", "Adidas"};
float rating_brand[100] = {5.0, 5.0, 4.5, 3.0, 4.0, 4.5, 3.5, 3.0, 3.5};
int indeks = 9;

// Fungsi untuk mencari indeks brand berdasarkan nama
int cariIndeksBrand(string nama) {
    for (int i = 0; i < sizeof(brand_baju) / sizeof(*brand_baju); i++) {
        if (brand_baju[i] == nama) {
            return i;
        }
    }
    return -1; // Jika tidak ditemukan
}

// Fungsi untuk menampilkan menu dan meminta input pilihan
int tampilkanMenu() {
    int pilih;
    cout << endl;
    cout << "========================================" << endl;
    cout << "M E N U" << endl;
    cout << "1. Create" << endl;
    cout << "2. Read" << endl;
    cout << "3. Update" << endl;
    cout << "4. Delete" << endl;
    cout << "5. Exit" << endl;
    cout << "========================================" << endl;
    cout << "Pilih Menu : ";
    cin >> pilih;
    return pilih;
}

// Prosedur untuk menambah data brand dan rating
void tambah() {
    string ulang, nama;
    float rating;
    while (true) {
        cout << "Masukkan nama brand baju : ";
        fflush(stdin);
        getline(cin, nama);
        brand_baju[indeks] = nama;

        cout << "Masukkan rating brand : ";
        cin >> rating;
        rating_brand[indeks] = rating;
        indeks++;

        cout << "Data berhasil ditambahkan :)" << endl;
        cout << "Tambah data lagi? (Ya/Tidak): ";
        fflush(stdin);
        getline(cin, ulang);

        if (ulang == "tidak") {
            break;
        }
    }
}

// Prosedur untuk menampilkan semua data brand dan rating
void lihat() {
    for (int i = 0; i < sizeof(brand_baju) / sizeof(*brand_baju); i++) {
        if (brand_baju[i] != "") {
            cout << i + 1 << endl;
            cout << "brand  : " << brand_baju[i] << endl;
            cout << "rating : " << rating_brand[i] << endl;
            cout << endl;
        }
    }
}

// Prosedur untuk mengupdate data brand dan rating
void update() {
    string nama;
    float rating;
    int index;

    cout << "Masukkan nama brand baju yang ingin diupdate : ";
    fflush(stdin);
    getline(cin, nama);

    index = cariIndeksBrand(nama);
    if (index != -1) {
        cout << "Masukkan rating brand baru : ";
        cin >> rating;

        rating_brand[index] = rating;
        cout << "Data berhasil diubah" << endl;
    } else {
        cout << "Brand tidak ditemukan." << endl;
    }
}

// Prosedur untuk menghapus data brand dan rating
void hapus() {
    int index;

    cout << "Masukkan nomor brand baju yang ingin dihapus : "; cin >> index;

    
    if (index != -1) {
        for (int i = index-1; i < sizeof(brand_baju) / sizeof(*brand_baju); i++) {
            brand_baju[i] = brand_baju[i + 1];
            rating_brand[i] = rating_brand[i + 1];
        }
        indeks--;
        cout << "Data berhasil dihapus" << endl;
    } else {
        cout << "Brand tidak ditemukan." << endl;
    }
}

int main() {
    int ulang = 2;
    while (ulang != -1) {
        string nama, nim;
        int pilih = 0;

        cout << "Masukkan Nama Anda : ";
        fflush(stdin);
        getline(cin, nama);
        cout << "Masukkan Nim Anda : ";
        fflush(stdin);
        getline(cin, nim);

        if (nama == "Tiara Kasma Wati Putri" && nim == "2309106080") {
            while (pilih != 5) {
                pilih = tampilkanMenu();
                switch (pilih) {
                    case 1:
                        tambah();
                        break;
                    case 2:
                        lihat();
                        break;
                    case 3:
                        update();
                        break;
                    case 4:
                        hapus();
                        break;
                    case 5:
                        cout << "Terima kasih telah menggunakan program ini." << endl;
                        return 0;
                    default:
                        cout << "Inputan anda salah!!" << endl;
                        break;
                }
            }
        } else {
            cout << "Nama atau Nim anda salah !! coba lagi !!" << endl;
            ulang--;
            if (ulang == -1) {
                return 0;
            }
        }
    }
}
