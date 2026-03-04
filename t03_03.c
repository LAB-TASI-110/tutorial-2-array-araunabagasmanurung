#include <stdio.h>    // Diperlukan untuk fungsi input/output seperti printf dan scanf
#include <limits.h>   // Diperlukan untuk INT_MAX dan INT_MIN
#include <float.h>    // Diperlukan untuk DBL_MAX dan DBL_MIN (untuk inisialisasi rata-rata)

int main() {
    int n;           // Variabel untuk menyimpan jumlah angka yang akan dimasukkan
    int angka;       // Variabel untuk menyimpan setiap angka yang dimasukkan
    int min_val = INT_MAX; // Inisialisasi nilai minimum dengan nilai integer terbesar yang mungkin
    int max_val = INT_MIN; // Inisialisasi nilai maksimum dengan nilai integer terkecil yang mungkin

    double min_avg_consecutive = DBL_MAX; // Inisialisasi rata-rata terendah dengan nilai double terbesar yang mungkin
    double max_avg_consecutive = DBL_MIN; // Inisialisasi rata-rata tertinggi dengan nilai double terkecil yang mungkin

    int prev_angka = 0; // Menyimpan angka sebelumnya untuk perhitungan rata-rata berturut-turut
    int has_at_least_one_pair = 0; // Flag untuk menentukan apakah sudah ada setidaknya satu pasangan angka yang dihitung rata-ratanya

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

        // Logika untuk menghitung rata-rata dua angka berturut-turut
        if (i > 0) { // Kita butuh setidaknya dua angka untuk membentuk pasangan
            double current_avg = (double)(prev_angka + angka) / 2.0;

            // Update nilai rata-rata terendah
            if (current_avg < min_avg_consecutive) {
                min_avg_consecutive = current_avg;
            }

            // Update nilai rata-rata tertinggi
            if (current_avg > max_avg_consecutive) {
                max_avg_consecutive = current_avg;
            }
            has_at_least_one_pair = 1; // Set flag karena sudah ada pasangan yang diproses
        }
        prev_angka = angka; // Simpan angka saat ini untuk digunakan sebagai 'prev_angka' di iterasi berikutnya
    }

    // Menampilkan hasil nilai terkecil dan terbesar
    printf("%d\n", min_val);
    printf("%d\n", max_val);

    // Menampilkan rata-rata terendah dan tertinggi jika ada cukup data (n >= 2)
    if (has_at_least_one_pair) { // Hanya cetak jika minimal ada satu pasangan rata-rata yang dihitung
        printf("%.2lf\n", min_avg_consecutive);
        printf("%.2lf\n", max_avg_consecutive);
    } else {
        // Opsional: Pesan jika tidak ada cukup angka untuk rata-rata
        // printf("Tidak cukup angka untuk menghitung rata-rata pasangan.\n");
    }

    return 0; // Mengindikasikan program berhasil dieksekusi
}