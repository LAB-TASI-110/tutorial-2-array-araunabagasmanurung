#include <stdio.h>    // Diperlukan untuk fungsi input/output seperti scanf dan printf
#include <limits.h>   // Diperlukan untuk INT_MAX dan INT_MIN
#include <float.h>    // Diperlukan untuk DBL_MAX (untuk inisialisasi rata-rata)

int main() {
    int n;           // Variabel untuk menyimpan jumlah angka yang akan dimasukkan
    int angka;       // Variabel untuk menyimpan setiap angka yang dimasukkan
    int min_val = INT_MAX; // Inisialisasi nilai minimum
    int max_val = INT_MIN; // Inisialisasi nilai maksimum

    double min_avg_consecutive = DBL_MAX; // Inisialisasi rata-rata terendah dengan nilai double terbesar
    int prev_angka = 0; // Menyimpan angka sebelumnya
    int has_at_least_one_pair = 0; // Flag untuk melacak apakah ada setidaknya satu pasangan rata-rata yang dihitung

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

        // Logika untuk menghitung rata-rata dua angka berturut-turut
        if (i > 0) { // Kita butuh setidaknya dua angka untuk membentuk pasangan
            double current_avg = (double)(prev_angka + angka) / 2.0;

            // Update nilai rata-rata terendah
            if (current_avg < min_avg_consecutive) {
                min_avg_consecutive = current_avg;
            }
            has_at_least_one_pair = 1; // Set flag karena sudah ada pasangan yang diproses
        }
        prev_angka = angka; // Simpan angka saat ini untuk digunakan sebagai 'prev_angka' di iterasi berikutnya
    }

    // Menampilkan hasil nilai terkecil dan terbesar
    printf("%d\n", min_val);
    printf("%d\n", max_val);

    // Menampilkan rata-rata terendah jika ada cukup data (n >= 2)
    if (has_at_least_one_pair) {
        printf("%.2lf\n", min_avg_consecutive);
    }

    return 0; // Mengindikasikan program berhasil dieksekusi
}