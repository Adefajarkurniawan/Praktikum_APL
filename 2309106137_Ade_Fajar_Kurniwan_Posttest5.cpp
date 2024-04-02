#include <iostream>
#include <string>

using namespace std;

struct JamPraktek {
    string mulai;
    string selesai;
};

struct JadwalDokter {
    string nama;
    string spesialis;
    JamPraktek jamPraktek;
};

const int MAX_JADWAL = 50;
JadwalDokter jadwalDokterList[MAX_JADWAL];
int jumlahJadwal = 0;

void delay() {
    cout << "Tekan untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

void tambahJadwal(JadwalDokter* jadwal) {
    if (jumlahJadwal < MAX_JADWAL) {
        cout << "Nama Dokter: ";
        getline(cin, jadwal->nama);
        cout << "Spesialis: ";
        getline(cin, jadwal->spesialis);
        cout << "Jam Mulai: ";
        getline(cin, jadwal->jamPraktek.mulai);
        cout << "Jam Selesai: ";
        getline(cin, jadwal->jamPraktek.selesai);
        jumlahJadwal++;
        cout << "Jadwal berhasil ditambahkan." << endl;
    } else {
        cout << "Maaf, jumlah jadwal sudah mencapai batas maksimum." << endl;
    }
    delay();
}

void lihatJadwal() {
    if (jumlahJadwal > 0) {
        cout << "Jadwal Praktek Dokter:" << endl;
        for (int i = 0; i < jumlahJadwal; ++i) {
            cout << "Nama: " << jadwalDokterList[i].nama << endl;
            cout << "Spesialis: " << jadwalDokterList[i].spesialis << endl;
            cout << "Jam Praktek: " << jadwalDokterList[i].jamPraktek.mulai << " - " << jadwalDokterList[i].jamPraktek.selesai << endl;
            cout << "-----------------------------------" << endl;
        }
    } else {
        cout << "Belum ada jadwal praktek dokter yang ditambahkan." << endl;
    }
    delay();
}

void updateJadwal(JadwalDokter* jadwal) {
    if (jumlahJadwal > 0) {
        cout << "Pilih dokter yang akan diupdate jadwalnya (1-" << jumlahJadwal << "): ";
        int index;
        cin >> index;
        cin.ignore(); // Membersihkan newline dari buffer

        if (index >= 1 && index <= jumlahJadwal) {
            cout << "Nama Dokter: ";
            getline(cin, jadwalDokterList[index - 1].nama);
            cout << "Spesialis: ";
            getline(cin, jadwalDokterList[index - 1].spesialis);
            cout << "Jam Mulai: ";
            getline(cin, jadwalDokterList[index - 1].jamPraktek.mulai);
            cout << "Jam Selesai: ";
            getline(cin, jadwalDokterList[index - 1].jamPraktek.selesai);
            cout << "Jadwal berhasil diupdate." << endl;
        } else {
            cout << "Nomor dokter tidak valid." << endl;
        }
    } else {
        cout << "Belum ada jadwal praktek dokter yang ditambahkan." << endl;
    }
    delay();
}

void hapusJadwal(JadwalDokter* jadwal) {
    if (jumlahJadwal > 0) {
        cout << "Pilih dokter yang akan dihapus jadwalnya (1-" << jumlahJadwal << "): ";
        int index;
        cin >> index;
        cin.ignore(); // Membersihkan newline dari buffer

        if (index >= 1 && index <= jumlahJadwal) {
            for (int i = index - 1; i < jumlahJadwal - 1; ++i) {
                jadwalDokterList[i] = jadwalDokterList[i + 1];
            }
            jumlahJadwal--;
            cout << "Jadwal berhasil dihapus." << endl;
        } else {
            cout << "Nomor dokter tidak valid." << endl;
        }
    } else {
        cout << "Belum ada jadwal praktek dokter yang ditambahkan." << endl;
    }
    delay();
}

void menu() {
    char pilihan;
    do {
        system("cls");
        cout << "=========================================" << endl;
        cout << "MENU UTAMA" << endl;
        cout << "=========================================" << endl;
        cout << "1. Tambah Jadwal Praktek Dokter" << endl;
        cout << "2. Lihat Jadwal Praktek Dokter" << endl;
        cout << "3. Update Jadwal Praktek Dokter" << endl;
        cout << "4. Hapus Jadwal Praktek Dokter" << endl;
        cout << "5. Keluar" << endl;
        cout << "=========================================" << endl;
        cout << "Pilih Opsi: ";
        cin >> pilihan;
        cin.ignore(); // Membersihkan newline dari buffer

        switch (pilihan) {
            case '1':
                tambahJadwal(&jadwalDokterList[jumlahJadwal]);
                break;
            case '2':
                lihatJadwal();
                break;
            case '3':
                updateJadwal(&jadwalDokterList[jumlahJadwal]);
                break;
            case '4':
                hapusJadwal(&jadwalDokterList[jumlahJadwal]);
                break;
            case '5':
                cout << "Terima kasih telah menggunakan program ini." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
    } while (pilihan != '5');
}

int main() {
    menu();
    return 0;
}
