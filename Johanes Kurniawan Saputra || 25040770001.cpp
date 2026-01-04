#include <iostream>
#include <string>
#include <ctime>
#include <limits>
#include <algorithm>

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
        cout << "Plat Nomor        : ";
        getline(cin, platNomor);

        cout << "Jenis Kendaraan   : ";
        getline(cin, jenis);

        waktuMasuk = time(NULL);
        cout << "\nKendaraan MASUK...\n";
        cout << "Waktu masuk tercatat.\n";
    }

    void kendaraanKeluar() {
        waktuKeluar = time(NULL);
        durasi = static_cast<int>(difftime(waktuKeluar, waktuMasuk));
        hitungBiaya();
    }

    void hitungBiaya() {
        int biayaAwal = 2000;
        int biayaPerDetik = 1000;
        int biayaMaks = 10000;

        if (durasi <= 10) {
            biaya = 0;
        } else {
            int detikBayar = durasi - 10;
            biaya = biayaAwal + max(0, detikBayar - 1) * biayaPerDetik;
        }

        if (biaya > biayaMaks)
            biaya = biayaMaks;
    }

    void tampilData() {
        cout << "\n===== STRUK PARKIR =====\n";
        cout << "Plat Nomor    : " << platNomor << endl;
        cout << "Jenis         : " << jenis << endl;
        cout << "Durasi Parkir : " << durasi << " detik\n";
        cout << "Total Biaya   : Rp" << biaya << endl;
    }
};

int main() {
    Parkir p;

    cout << "=== SISTEM PARKIR OOP (AUTO TIME) ===\n\n";

    p.kendaraanMasuk();

    cout << "\nTekan ENTER untuk kendaraan keluar...";
    cin.get();

    p.kendaraanKeluar();
    p.tampilData();

    cout << "\nTekan ENTER untuk keluar...";
    cin.get();

    return 0;
}
