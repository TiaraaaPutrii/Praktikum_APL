#include <iostream>
using namespace std;

int indeks = 9;

struct brand
{
    string brand_baju;
    float rating_brand;
};

struct DATA_BRAND
{
    struct brand br[50];
};
DATA_BRAND db;

// Fungsi untuk mencari indeks brand berdasarkan nama
int cariIndeksBrand(string nama)
{
    for (int i = 0; i < sizeof(db.br) / sizeof(*db.br); i++)
    {
        if (db.br[i].brand_baju == nama)
        {
            return i;
        }
    }
    return -1; // Jika tidak ditemukan
}

// Fungsi untuk menampilkan menu dan meminta input pilihan
int tampilkanMenu()
{
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
void tambah()
{
    string ulang, nama;
    float rating;
    while (true)
    {
        cout << "Masukkan nama brand baju : ";
        fflush(stdin);
        getline(cin, nama);
        db.br[indeks].brand_baju = nama;

        cout << "Masukkan rating brand : ";
        cin >> rating;
        db.br[indeks].rating_brand = rating;
        indeks++;

        cout << "Data berhasil ditambahkan :)" << endl;
        cout << "Tambah data lagi? (Ya/Tidak): ";
        fflush(stdin);
        getline(cin, ulang);

        if (ulang == "tidak")
        {
            break;
        }
    }
}

// Prosedur untuk menampilkan semua data brand dan rating
void lihat()
{
    for (int i = 0; i < sizeof(db.br) / sizeof(*db.br); i++)
    {
        if (db.br[i].brand_baju != "")
        {
            cout << i + 1 << endl;
            cout << "brand  : " << db.br[i].brand_baju << endl;
            cout << "rating : " << db.br[i].rating_brand << endl;
            cout << endl;
        }
    }
}

// Prosedur untuk mengupdate data brand dan rating
void update()
{
    string nama;
    float rating;
    int index;

    cout << "Masukkan nomor brand baju yang ingin diupdate : ";
    fflush(stdin);
    getline(cin, nama);

    index = cariIndeksBrand(nama);
    if (index < sizeof(db.br) / sizeof(*db.br))
    {

        cout << "Masukkan nama brand baru : ";
        fflush(stdin);
        getline(cin, nama);
        db.br[index].brand_baju = nama;

        cout << "Masukkan rating brand baru : ";
        cin >> rating;

        db.br[index].rating_brand = rating;
        cout << "Data berhasil diubah" << endl;
    }
    else
    {
        cout << "Brand tidak ditemukan." << endl;
    }
}

// Prosedur untuk menghapus data brand dan rating
void hapus()
{
    int index;

    cout << "Masukkan nomor brand baju yang ingin dihapus : ";
    cin >> index;

    if (index > sizeof(db.br) / sizeof(*db.br))
    {
        for (int i = index - 1; i < sizeof(db.br) / sizeof(*db.br); i++)
        {
            db.br[i].brand_baju = db.br[i + 1].brand_baju;
            db.br[i].rating_brand = db.br[i + 1].rating_brand;
        }
        indeks--;
        cout << "Data berhasil dihapus" << endl;
    }
    else
    {
        cout << "Brand tidak ditemukan." << endl;
    }
}

//Tiara Kasma Wati Putri
//2309106080

int main()
{

    db.br[0] = {"Gucci", 5.0};
    db.br[1] = {"Chanel", 5.0};
    db.br[2] = {"Versace", 4.5};
    db.br[3] = {"Nike", 3.0};
    db.br[4] = {"Zara", 4.0};
    db.br[5] = {"Celine", 4.5};
    db.br[6] = {"Balenciaga", 3.5};
    db.br[7] = {"Puma", 3.0};
    db.br[7] = {"Adidas", 3.5};

    int ulang = 2;
    while (ulang != -1)
    {
        string nama, nim;
        int pilih = 0;

        cout << "Masukkan Nama Anda : ";
        fflush(stdin);
        getline(cin, nama);
        cout << "Masukkan Nim Anda : ";
        fflush(stdin);
        getline(cin, nim);

        if (nama == "1" && nim == "2")
        {
            while (pilih != 5)
            {
                pilih = tampilkanMenu();
                switch (pilih)
                {
                case 1:
                    tambah();
                    break;
                case 2:
                    lihat();
                    break;
                case 3:
                    lihat();
                    update();
                    break;
                case 4:
                    lihat();
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
        }
        else
        {
            cout << "Nama atau Nim anda salah !! coba lagi !!" << endl;
            ulang--;
            if (ulang == -1)
            {
                return 0;
            }
        }
    }
}
