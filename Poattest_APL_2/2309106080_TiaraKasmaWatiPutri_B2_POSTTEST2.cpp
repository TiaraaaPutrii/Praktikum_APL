#include <iostream>
using namespace std;

string brand_baju [100] = {"Gucci", "Chanel", "Versace", "Nike", "Zara", "Celine", "Balenciaga", "Puma", "Adidas"};
float rating_brand [100] = {5.0, 5.0, 4.5, 3.0, 4.0, 4.5, 3.5, 3.0, 3.5};
int indeks = 9;


void tambah(){
    string ulang, nama;
    float rating;
    while(true){
        cout << "Masukkan nama brand baju : "; fflush(stdin); getline(cin, nama);
        brand_baju[indeks] = nama;
        
        cout << "Masukkan rating brand : "; cin >> rating;
        rating_brand[indeks] = rating;
        indeks++;

        cout << "Data berhasil ditambahkan :)" << endl;
        cout << "Tambah data lagi? (Ya/Tidak): "; fflush(stdin); getline(cin, ulang);

        if (ulang == "ya"){
        }
        else if(ulang == "tidak"){
            break;
        }
    }
}

void lihat(){
    for(int i = 0; i < sizeof(brand_baju)/sizeof(*brand_baju); i++){
        if(brand_baju[i] != "" ){
            cout << i+1 << endl;
            cout << "brand  : " << brand_baju[i] << endl;
            cout << "rating : " << rating_brand[i] << endl;
            cout << endl;
        }
    }
};

void update(){
    int index,rating;
    string nama;
    cout << "Pilih No yang ingin diupdate : " ; cin >> index;
    cout << "Masukkan nama brand baju : "; fflush(stdin); getline(cin, nama);
    brand_baju[index-1] = nama;
    
    cout << "Masukkan rating brand : "; cin >> rating;
    rating_brand[index-1] = rating;
    cout << "Data berhasil diubah" << endl;
}

void hapus(){
    int index;
    cout << "Pilih nomor yang ingin dihapus : " ; cin >> index;
    for(int i = index; i < sizeof(brand_baju)/sizeof(*brand_baju); i++){
        brand_baju[i-1] = brand_baju[i];
        rating_brand[i-1] = rating_brand[i];
    }indeks--;
}

int main (){


    int pilih, ulang;
    int n = 0; //indeks array
    string nama, nim, menu;

    ulang = 2;
    while(ulang != -1){
       cout << "Masukkan Nama Anda : "; fflush(stdin); getline (cin, nama);
       cout << "Masukkan Nim Anda : "; fflush(stdin); getline (cin, nim);
       if (nama == "Tiara Kasma Wati Putri" && nim == "2309106080"){
               while(pilih != 5){
               cout << endl;
               cout << "========================================" << endl;
               cout << "M E N U" << endl;
               cout << "1. Create" << endl;
               cout << "2. Read" << endl;
               cout << "3. Update" << endl;
               cout << "4. Delete" << endl;
               cout << "5. Exit" << endl;
               cout << "========================================" << endl;
               cout << "Pilih Menu : "; cin >> pilih;

               if(pilih == 1){
                tambah();
                  
               } else if (pilih == 2){
                lihat();
               }
                else if (pilih == 3){
                lihat();
                update();
               }
                else if (pilih == 4){
                hapus();
               }
               else{
                cout << "Inputan anda salah!!" << endl;
               }
            }
       }
       else{
            cout << "Nama atau Nim anda salah !! coba lagi !!" << endl;
            ulang--;
            if(ulang == -1){
                return 0;
            }
       }
    }
}
