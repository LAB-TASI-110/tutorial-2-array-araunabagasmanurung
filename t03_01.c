#include <stdio.h> // Diperlukan untuk fungsi input/output seperti printf dan scanf
#include <limits.h> // Diperlukan untuk INT_MAX dan INT_MIN

int main() {
    int n; // Variabel untuk menyimpan jumlah angka yang akan dimasukkan
    int angka; // Variabel untuk menyimpan setiap angka yang dimasukkan
    int min_val = INT_MAX; // Inisialisasi nilai minimum dengan nilai integer terbesar yang mungkin
    int max_val = INT_MIN; // Inisialisasi nilai maksimum dengan nilai integer terkecil yang mungkin

    // Pesan untuk pengguna agar memasukkan jumlah angka (n)
    printf("Masukkan jumlah angka yang akan Anda proses: ");
    // Membaca nilai n dari input pengguna
    scanf("%d", &n);

    // Memastikan n adalah angka positif
    if (n <= 0) {
        printf("Jumlah angka harus lebih dari 0.\n");
        return 1; // Keluar dengan kode error
    }

    // Loop untuk membaca n angka dari pengguna
    printf("Masukkan %d angka (pisahkan dengan spasi atau enter):\n", n);
    for (int i = 0; i < n; i++) {
        // Membaca setiap angka
        scanf("%d", &angka);

        // Membandingkan dengan nilai minimum saat ini
        if (angka < min_val) {
            min_val = angka;
        }

        // Membandingkan dengan nilai maksimum saat ini
        if (angka > max_val) {
            max_val = angka;
        }
    }

    // Menampilkan hasil nilai terkecil dan terbesar
    printf("Nilai terkecil: %d\n", min_val);
    printf("Nilai terbesar: %d\n", max_val);

    return 0; // Mengindikasikan program berhasil dieksekusi
}