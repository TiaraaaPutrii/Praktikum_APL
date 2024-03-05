#include <iostream>
using namespace std;

int main(){
    int pilih, ulang;
    double kecepatan;
    string nama, nim;

    ulang = 2;
    while(ulang != -1){
        cout << "Masukkan Nim Anda  : "; fflush(stdin); getline (cin, nim);
        cout << "Masukkan Nama Anda : "; fflush(stdin); getline (cin, nama);
        if (nama == "Tiara Kasma Wati Putri" && nim == "2309106080"){
                while(pilih != 5){
                cout << endl;
                cout << "Program Konversi Kecepatan" << endl;
                cout << "=====================" << endl;
                cout << "1. Km/jam       -> Cm/detik, Meter/ detik, Mil/jam " << endl;
                cout << "2. Cm/detik     -> Km/jam, Meter/detik, Mil/jam" << endl;
                cout << "3. Meter/detik  -> Km/jam, Cm/Detik, Mil/jam" << endl;
                cout << "4. Mil/jam      -> Km/jam, Cm/detik, Meter/detik" << endl;
                cout << "5. Exit" << endl;
                cout <<"pilih menu : "; cin >> pilih;

                if(pilih == 1){
                    cout << endl;
                    cout << "masukkan kecepatan Km/jam : "; cin >> kecepatan;
                    cout << kecepatan * 27.777778 << " Cm/detik" << endl;
                    cout << kecepatan * 0.27777778 << " Meter/detik" << endl;
                    cout << kecepatan * 0.62137119 << " Mil/jam" << endl;
                }
                else if (pilih == 2){
                    cout << endl;
                    cout << "masukkan kecepatan Cm/detik : "; cin >> kecepatan;
                    cout << kecepatan * 0.036 << " Km/jam" << endl;
                    cout << kecepatan + 0.01 << " Meter/detik" << endl;
                    cout << kecepatan * 0.022369363 << " Mil/jam" << endl;
                }
                else if (pilih == 3){
                    cout << endl;
                    cout << "masukkan kecepatan Meter/detik : "; cin >> kecepatan;
                    cout << kecepatan * 3.6  << " Km/jam" << endl;
                    cout << kecepatan * 0.01 << " Cm/detik" << endl;
                    cout << kecepatan * 2.2369363 << " Mil/jam" << endl;
                }
                else if (pilih == 4){
                    cout << endl;
                    cout << "masukkan kecepatan Mil/jam : "; cin >> kecepatan;
                    cout << kecepatan * 1.609344 << " Km/jam" << endl;
                    cout << kecepatan * 44.704 << " Cm/detik" << endl;
                    cout << kecepatan * 0.44704 << " Meter/detik" << endl; 
                }
                else if (pilih == 5){
                    return 0;
                }
                else{
                    cout << "salah memilih menu!!!" << endl;
                }
            }
        }
        else{
            cout << "nim atau nama yang anda input mungkin salah" << endl;
            cout << "kesempatan anda tersisa " << ulang << " kali" << endl;
            ulang--;
            if (ulang == -1){
                cout << "kesempatan anda telah habis" << endl;
                return 0;
            }
        }
    }
    

    
}
