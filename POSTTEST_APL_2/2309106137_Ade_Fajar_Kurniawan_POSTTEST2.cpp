#include<iostream>

using namespace std;

string jadwal_dokter [20][4];
int jumlah_dokter = 0;

void delay(){
    cout << "Tekan Untuk Melanjutkan...";
    cin.ignore();
    cin.get();
}   

void tambah_jadwal(){
    system("CLS");
     if(jumlah_dokter >= 1){
        for (int i = 0; i < jumlah_dokter; ++i) {
            cout << i + 1 << ". Nama: " << jadwal_dokter[i][0] << endl;
            cout << "   " << "Spesialis: " << jadwal_dokter[i][1] << endl; 
            cout << "   " << "Jam Mulai: " << jadwal_dokter[i][2] << endl;
            cout << "   " << "Jam Selesai: " << jadwal_dokter[i][3] << endl;
        }
    }
    cout << "Nama Dokter: ";
    cin >> jadwal_dokter[jumlah_dokter][0];
    cout << "Spesialis: ";
    cin >> jadwal_dokter[jumlah_dokter][1];
    cout << "Jam Mulai: ";
    cin >> jadwal_dokter[jumlah_dokter][2];
    cout << "Jam Selesai: ";
    cin >> jadwal_dokter[jumlah_dokter][3];
    jumlah_dokter++;
    delay();
    
}

void lihat_jadwal(){  
    system("CLS");
    if(jumlah_dokter >= 1){
        for (int i = 0; i < jumlah_dokter; ++i) {
            cout << i + 1 << ". Nama: " << jadwal_dokter[i][0] << endl;
            cout << "   " << "Spesialis: " << jadwal_dokter[i][1] << endl; 
            cout << "   " << "Jam Mulai: " << jadwal_dokter[i][2] << endl;
            cout << "   " << "Jam Selesai: " << jadwal_dokter[i][3] << endl;
        }
    }else{
        cout << "Belom Ada Jadwal Yang Tersedia" << endl;
    }
    delay();        
}

void update_jadwal(){
    system("CLS");
    for(int i=0; i < jumlah_dokter; i++){
        cout << i+1 << ". Nama: " << jadwal_dokter[i][0]<< endl;
        cout<<"   " << "Spesialis: " << jadwal_dokter[i][1]<< endl; 
        cout<<"   " << "Jam Muai: " << jadwal_dokter[i][2]<< endl;
        cout<<"   " << "Jam Selesai: " << jadwal_dokter[i][3]<< endl;
    }
    int index;
    cout << "Pilih ID Dokter Yang Akan Di Ubah: "; cin >> index;
    string nama,spesialis,jam_mulai,jam_selesai;

    if (index >= 1 and index <= jumlah_dokter){
    cout << "Masukan Nama Dokter: ";   
    cin >> jadwal_dokter[index-1][0];
    cout << "Masukkan Spesialis: ";
    cin >> jadwal_dokter[index-1][1];
    cout << "Masukkan Jam Mulai: ";
    cin >> jadwal_dokter[index-1][2];
    cout << "Masukkan Jam Selesai: ";
    cin >> jadwal_dokter[index-1][3];
    delay();
    }else{
        cout << "ID Dokter Tidak Ditemukan\n";
        delay();
    }
}

void hapus_jadwal(){
    system("CLS");
    int index;
    for(int i=0; i < jumlah_dokter; i++){
        cout << i+1 << ". Nama: " << jadwal_dokter[i][0]<< endl;
        cout<<"   " << "Spesialis: " << jadwal_dokter[i][1]<< endl; 
        cout<<"   " << "Jam Mulai: " << jadwal_dokter[i][2]<< endl;
        cout <<"   " << "Jam Selesai: " << jadwal_dokter[i][3]<< endl;
    }

    int nomor;
    cout << "Pilih ID Dokter Yang Akan Di Hapus: ";
    cin >> nomor;
    if(nomor >=1 and nomor <= jumlah_dokter){
        for (int i = nomor - 1; i < jumlah_dokter - 1; ++i) {
            jadwal_dokter[i][0] = jadwal_dokter[i + 1][0];
            jadwal_dokter[i][1] = jadwal_dokter[i + 1][1];
            jadwal_dokter[i][2] = jadwal_dokter[i + 1][2];
        }
        jumlah_dokter--;
        cout << "Jadwal berhasil dihapus." << endl;
        delay();
    } else {
        cout << "Nomor jadwal tidak valid." << endl;
        delay();
    }
}

void login(){
    system("CLS");
    int coba = 0;
    string username = "Ade";
    string password = "137";
    string userlogin, passlogin;
    string pilih;

    while(true){
    system("CLS");
    cout << "--  Menu Login --\n";
    cout << "[1] LOGIN\n";
    cout << "[2] KELUAR\n";
    cout << "PILIH OPSI: ";
    cin >> pilih;
    if(pilih == "1"){
        delay();
        while(coba < 3){
            system("CLS");
            cout << "--  Menu Login --\n";
            cout << "\nUSERNAME: ";
            cin >> userlogin;
            cout << "PASSWORD: ";
            cin >> passlogin;
            if (userlogin == username and passlogin == password){
                cout << "LOGIN BERHASIL " << username<< endl;
                delay();
                return;
    
            }else{
                cout << "LOGIN GAGAL" << endl;
                delay();
                coba++;
                if (coba == 3){
                    cout << "Login Melewati Batas Percobaan" << endl << "Program Di Hentikan";
                    exit(0);
                }
                
            }
        }
    }else if(pilih =="2"){
        exit(0);
    }else{
       delay();
       cout << "OPSI TIDAK VALID" << endl;
    }
    }
}
 
int main(){
    login();
    string pilih;
    while (true){  
        system("CLS");
        cout << "JADWAL PRAKTEK DOKTER\n";
        cout << "1. TAMBAH JADWAL PRAKTEK DOKTER\n";
        cout << "2. LIHAT JADWAL PRAKTEK DOKTER\n";
        cout << "3. UPDTE JADWAL PRAKTEK DOKTER\n";
        cout << "4. HAPUS JADWAL PRAKTEK DOKTER\n";
        cout << "5. LOGOUT\n"; 
        cout << "PILIH OPSI: ";
        cin >> pilih;
        if(pilih == "1"){
            delay();
            tambah_jadwal();
            
        }else if (pilih == "2"){
            delay();
            lihat_jadwal();            
        }else if(pilih == "3"){
            delay();
            update_jadwal();
        }else if(pilih == "4"){
            delay();;
            hapus_jadwal();
        }else if(pilih == "5"){
            delay();
            login();
        }else{
            delay();
            cout << "Opsi Tidak Ada ";
        }
     
    }
    return 0;
}

