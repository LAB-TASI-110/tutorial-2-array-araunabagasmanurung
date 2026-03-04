#include <stdio.h>    // Diperlukan untuk fungsi input/output seperti scanf dan printf
#include <limits.h>   // Diperlukan untuk INT_MAX dan INT_MIN

int main() {
    int n;           // Variabel untuk menyimpan jumlah angka yang akan dimasukkan
    int angka;       // Variabel untuk menyimpan setiap angka yang dimasukkan
    int min_val = INT_MAX; // Inisialisasi nilai minimum
    int max_val = INT_MIN; // Inisialisasi nilai maksimum

    // Membaca nilai n dari input pengguna (tanpa prompt)
    scanf("%d", &n);

    // Menangani kasus n <= 0 (tanpa pesan error ke stdout)
    if (n <= 0) {
        return 1; // Keluar dengan kode error
    }

    // Loop untuk membaca n angka dari pengguna (tanpa prompt)
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
    printf("%d\n", min_val);
    printf("%d\n", max_val);

    return 0; // Mengindikasikan program berhasil dieksekusi
}