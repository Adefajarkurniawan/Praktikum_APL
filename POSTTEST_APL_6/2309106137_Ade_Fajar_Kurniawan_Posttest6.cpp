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

string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
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

void search_nama() {
    string searchName;
    cout << "Masukkan nama dokter yang ingin Anda cari: ";
    getline(cin, searchName);
    searchName = toLower(searchName); // Convert searchName to lowercase

    // Melakukan binary search pada data yang diurutkan (berdasarkan nama)
    int left = 0;
    int right = jumlahJadwal - 1;
    bool found = false;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Memeriksa apakah nama dokter pada posisi mid sama dengan yang dicari
        if (toLower(jadwalDokterList[mid].nama) == searchName) {
            cout << "Jadwal Dokter:" << endl;
            cout << "Nama: " << jadwalDokterList[mid].nama << endl;
            cout << "Spesialis: " << jadwalDokterList[mid].spesialis << endl;
            cout << "Jam Praktek: " << jadwalDokterList[mid].jamPraktek.mulai << " - " << jadwalDokterList[mid].jamPraktek.selesai << endl;
            found = true;
            break;
        }
        // Jika nama yang dicari lebih kecil dari nama di tengah, cari di sebelah kiri
        else if (toLower(jadwalDokterList[mid].nama) > searchName) {
            right = mid - 1;
        }
        // Jika nama yang dicari lebih besar dari nama di tengah, cari di sebelah kanan
        else {
            left = mid + 1;
        }
    }

    if (!found) {
        cout << "Dokter dengan nama '" << searchName << "' tidak ditemukan." << endl;
    }
    delay();
}

void searchSpesialis() {
    string searchSpesialis;
    cout << "Masukkan spesialis yang ingin Anda cari: ";
    getline(cin, searchSpesialis);
    searchSpesialis = toLower(searchSpesialis); // Convert searchSpesialis to lowercase

    bool found = false;
    for (int i = 0; i < jumlahJadwal; ++i) {
        if (toLower(jadwalDokterList[i].spesialis) == searchSpesialis) {
            if (!found) {
                cout << "Daftar Dokter dengan Spesialis " << searchSpesialis << ":" << endl;
            }
            cout << "Nama: " << jadwalDokterList[i].nama << endl;
            cout << "Spesialis: " << jadwalDokterList[i].spesialis << endl;
            cout << "Jam Praktek: " << jadwalDokterList[i].jamPraktek.mulai << " - " << jadwalDokterList[i].jamPraktek.selesai << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Dokter dengan spesialis '" << searchSpesialis << "' tidak ditemukan." << endl;
    }
    delay();
}

void selectionSort_spesialis() {
    for (int i = 0; i < jumlahJadwal - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < jumlahJadwal; ++j) {
            // Menggunakan toLower untuk membandingkan spesialis secara case-insensitive
            if (toLower(jadwalDokterList[j].spesialis) < toLower(jadwalDokterList[minIndex].spesialis)) {
                minIndex = j;
            }
        }
        // Menukar elemen
        if (minIndex != i) {
            swap(jadwalDokterList[i], jadwalDokterList[minIndex]);
        }
    }
    cout << "Sorting hasil berdasarkan spesialis selesai." << endl;
    // Menampilkan hasil sorting ke terminal
    for (int i = 0; i < jumlahJadwal; ++i) {
        cout << "Nama: " << jadwalDokterList[i].nama << endl;
        cout << "Spesialis: " << jadwalDokterList[i].spesialis << endl;
        cout << "Jam Praktek: " << jadwalDokterList[i].jamPraktek.mulai << " - " << jadwalDokterList[i].jamPraktek.selesai << endl;
    }
    delay();
}

void sort_nama() {
    for (int i = 0; i < jumlahJadwal - 1; ++i) {
        for (int j = 0; j < jumlahJadwal - i - 1; ++j) {
            if (toLower(jadwalDokterList[j].nama) > toLower(jadwalDokterList[j + 1].nama)) {
                swap(jadwalDokterList[j], jadwalDokterList[j + 1]);
            }
        }
    }
    cout << "Jadwal berhasil diurutkan berdasarkan nama dokter secara ascending." << endl;
    // Menampilkan hasil sorting ke terminal
    for (int i = 0; i < jumlahJadwal; ++i) {
        cout << "Nama: " << jadwalDokterList[i].nama << endl;
        cout << "Spesialis: " << jadwalDokterList[i].spesialis << endl;
        cout << "Jam Praktek: " << jadwalDokterList[i].jamPraktek.mulai << " - " << jadwalDokterList[i].jamPraktek.selesai << endl;
    }
    delay();
}

void insertionSort_sortjam() {
    for (int i = 1; i < jumlahJadwal; ++i) {
        JadwalDokter key = jadwalDokterList[i];
        int j = i - 1;
        // Pindahkan elemen dari jadwalDokterList[0..i-1] yang lebih besar dari key ke posisi satu di depan mereka
        while (j >= 0 && jadwalDokterList[j].jamPraktek.mulai > key.jamPraktek.mulai) {
            jadwalDokterList[j + 1] = jadwalDokterList[j];
            j = j - 1;
        }
        jadwalDokterList[j + 1] = key;
    }
    cout << "Sorting hasil berdasarkan jam mulai selesai." << endl;
    // Menampilkan hasil sorting ke terminal
    for (int i = 0; i < jumlahJadwal; ++i) {
        cout << "Nama: " << jadwalDokterList[i].nama << endl;
        cout << "Spesialis: " << jadwalDokterList[i].spesialis << endl;
        cout << "Jam Praktek: " << jadwalDokterList[i].jamPraktek.mulai << " - " << jadwalDokterList[i].jamPraktek.selesai << endl;
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
        cout << "5. Cari Jadwal Dokter" << endl;
        cout << "6. Cari Spesialis" << endl;
        cout << "7. Keluar" << endl;
        cout << "=========================================" << endl;
        cout << "Pilih Opsi: ";
        cin >> pilihan;
        cin.ignore(); // Membersihkan newline dari buffer

        switch (pilihan) {
            case '1':
                tambahJadwal(&jadwalDokterList[jumlahJadwal]);
                break;
            case '2':
                int input;
                cout << "1. Lihat Berdasarkan Nama Dokter" << endl;
                cout << "2. Lihat Berdasarkan Spesialis" << endl;
                cout << "3. Lihat Berdasarkan Jam Mulai" << endl;
                cout << "Pilih Opsi: ";
                cin >> input;
                if (input == 1) {
                   sort_nama();
                } else if (input == 2) {
                    selectionSort_spesialis();
                } else if (input == 3) {
                    insertionSort_sortjam();
                } else {
                    cout << "Opsi tidak ada." << endl;
                    delay();
                    menu();
                }
                break;
            case '3':
                updateJadwal(&jadwalDokterList[jumlahJadwal]);
                break;
            case '4':
                hapusJadwal(&jadwalDokterList[jumlahJadwal]);
                break;
            case '5':
                search_nama();
                break;
            case '6':
                searchSpesialis();
                break;
            case '7':
                cout << "Terima kasih telah menggunakan program ini." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
    } while (pilihan != '7');
}

int main() {
    menu();
    return 0;
}
