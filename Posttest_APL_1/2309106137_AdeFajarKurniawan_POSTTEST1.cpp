#include <iostream>
using namespace std;

int main() {
    string passlogin;
    string userlogin;
    int coba = 0;
    string username = "Ade";
    string password = "2309106137";

    while (coba < 3) {
        cout << "Username: ";
        cin >> userlogin;
        cout << "Password: ";
        cin >> passlogin;

        if (userlogin == username && passlogin == password) {
            cout << "Login Berhasil" << endl;
            break;
            
        } else {
            cout << "Username dan Password tidak sesuai" << endl;
            coba++;
            if (coba == 3){
                cout << "Progrm Berakhir";
                exit(0);
            }
           
        }
    }
    
    while (true){
        system("cls");
        cout << "KOVERSI SUHU\n";
        cout << "[1] Celcius\n";
        cout << "[2] Reaumur\n";
        cout << "[3] Farenheit\n";
        cout << "[4] Kelvin\n";
        cout << "[5] Keluar\n";
        cout << "Pilih Jenis Suhu (1/2/3/4/5): ";
        string pilih;
        cin >> pilih;
        if (pilih == "1" ){ 
            cout << "Masukkan Suhu dalam Derajat Celcius(C): ";
            double celcius;
            cin >> celcius;
            system("cls");
            cout << "[1] Reaumur\n";
            cout << "[2] Farenheit\n";
            cout << "[3] Kelvin\n";
            cout << "[4] Kembali\n";
            cout << "Koversi Menjadi: ";
            string suhu;
            cin >> suhu;
            if (suhu == "1"){
                float hasil = celcius * 4/5;
                cout << celcius << " Derajat Ceclius setara dengan " <<  hasil <<  " Derajat Reaumur(R) ";
                break;
            }else if(suhu == "2"){
                float hasil = celcius * 9/5 + 32;
                cout << celcius << " Derajat Ceclius setara dengan " <<  hasil <<  " Derajat Farenheit(F) ";
                break;
            }else if(suhu == "3"){
                float hasil = celcius + 273.15;
                cout << celcius << " Derajat Ceclius setara dengan " <<  hasil <<  " Derajat Kelvin(K) ";
                break;
            }else if (suhu == "4"){
                break;
            }
            else{
                cout << "Opsi Tidak Tersedia";
                
            }
        }else if(pilih == "2"){
            cout << "Masukkan Suhu dalam Derajat Reumur(R): ";
            double reaumur;
            cin >> reaumur;
            system("cls");
            cout << "[1] Celcius\n";
            cout << "[2] Farenheit\n";
            cout << "[3] Kelvin\n";
            cout << "[4] Kembali\n";
            cout << "Koversi Menjadi: ";
            string suhu;
            cin >> suhu;
            if (suhu == "1"){
                float hasil = reaumur * 5/4;
                cout << reaumur << " Derajat Reaumur setara dengan " <<  hasil <<  " Derajat Celcius(C) ";
                break;
            }else if(suhu == "2"){
                float hasil = reaumur * 9/4 + 32;
                cout << reaumur << " Derajat Reaumur setara dengan " <<  hasil <<  " Derajat Farenheit(F) ";
                break;
            }else if(suhu == "3"){
                float hasil = reaumur * 5/4 + 273.15;
                cout << reaumur << " Derajat Reaumur setara dengan " <<  hasil <<  " Derajat Kelvin(K) ";
                break;
            }else if (suhu == "4"){
                break;
            }
            else{
                cout << "Opsi Tidak Tersedi";
            }
    } else if(pilih == "3"){
            cout << "Masukkan Suhu dalam Derajat Fahrenheit(F): ";
            double fahrenheit;
            cin >> fahrenheit;
            system("cls");
            cout << "[1] Celcius\n";
            cout << "[2] Reaumur\n";
            cout << "[3] Kelvin\n";
            cout << "[4] Kembali\n";
            cout << "Koversi Menjadi: ";
            string suhu;
            cin >> suhu;
            if (suhu == "1"){
                float hasil = (fahrenheit - 32) / 1.8;
                cout << fahrenheit << " Derajat Fahrenheit(F) setara dengan " <<  hasil <<  " Derajat Celcius(C) ";
                break;
            }else if(suhu == "2"){
                float hasil = (fahrenheit - 32) / 2.25;
                cout << fahrenheit << " Derajat Fahrenheit(F) setara dengan " <<  hasil <<  " Derajat Reaumur(R) ";
                break;
            }else if(suhu == "3"){
                float hasil = (fahrenheit - 32) / 1.8 + 273.15;
                cout << fahrenheit << " Derajat Fahrenheit(F) setara dengan " <<  hasil <<  " Derajat Kelvin(K) ";
                break;
            }else if (suhu == "4"){
                break;
            }
            else{
                cout << "Opsi Tidak Tersedi";
            }
    } else if(pilih == "4"){
            cout << "Masukkan Suhu dalam Derajat Kelvin(K): ";
            double kelvin;
            cin >> kelvin;
            system("cls");
            cout << "[1] Celcius\n";
            cout << "[2] Reaumur\n";
            cout << "[3] Fahrenheit\n";
            cout << "[4] Kembali\n";
            cout << "Koversi Menjadi: ";
            string suhu;
            cin >> suhu;
            if (suhu == "1"){
                float hasil = kelvin - 273.15;
                cout << kelvin << " Derajat Kelvin(K) setara dengan " <<  hasil <<  " Derajat Celcius(C) ";
                break;
            }else if(suhu == "2"){
                float hasil = (4/5) * (kelvin - 273.15);
                cout << kelvin << " Derajat Kelvin(K) setara dengan " <<  hasil <<  " Derajat Reaumur ";
                break;
            }else if(suhu == "3"){
                float hasil = (9/5) * (kelvin - 273.15) + 32;
                cout << kelvin << " Derajat Kelvin(K) setara dengan " <<  hasil <<  " Derajat Fahrenheit(F) ";
                break;
            }else if (suhu == "4"){
                break;
            }
            else{
                cout << "Opsi Tidak Tersedi";
            }
    }else if (pilih == "5"){
            break;
    }else{
        break;
    }
    
    
    }
    return 0;
}