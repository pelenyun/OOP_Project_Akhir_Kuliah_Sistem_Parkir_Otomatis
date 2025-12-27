#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Parkir {
private:
    string platNomor;
    string jenis;
    time_t waktuMasuk;
    time_t waktuKeluar;
    int durasi;
    int biaya;

public:
    void kendaraanMasuk() {
        cout << "Plat Nomor      : ";
        cin >> platNomor;
        cout << "Jenis Kendaraan : ";
        cin >> jenis;

        waktuMasuk = time(0);
        cout << "Kendaraan MASUK...\n";
        cout << "Waktu masuk tercatat.\n";
    }

void kendaraanKeluar() {
    waktuKeluar = time(0);

    int detik = difftime(waktuKeluar, waktuMasuk);

    if (detik <= 600) {
        durasi = 0;
    } else {
        detik -= 600;
        durasi = detik / 3600;

        if (detik % 3600 != 0)
            durasi++;
    }

    hitungBiaya();
}

void hitungBiaya() {
    int biayaAwal = 2000;
    int biayaPerJam = 1000;
    int biayaMaks = 10000;

    if (durasi == 0) {
        biaya = 0; // GRATIS
    }
    else if (durasi == 1) {
        biaya = biayaAwal;
    }
    else {
        biaya = biayaAwal + (durasi - 1) * biayaPerJam;
    }

    if (biaya > biayaMaks)
        biaya = biayaMaks;
}

void tampilData() {
        cout << "\n===== STRUK PARKIR =====\n";
        cout << "Plat Nomor    : " << platNomor << endl;
        cout << "Jenis         : " << jenis << endl;
        cout << "Durasi Parkir : " << durasi << " Jam\n";
        cout << "Total Biaya   : Rp" << biaya << endl;
    }
};

int main() {
    Parkir p;

    cout << "=== SISTEM PARKIR OOP (AUTO TIME) ===\n\n";

    p.kendaraanMasuk();

    cout << "\nTekan ENTER untuk kendaraan keluar...";
    cin.ignore();
    cin.get();

    p.kendaraanKeluar();
    p.tampilData();

    return 0;
}


