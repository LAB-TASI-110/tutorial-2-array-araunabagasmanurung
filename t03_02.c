#include <stdio.h>    // Diperlukan untuk fungsi input/output seperti printf dan scanf
#include <limits.h>   // Diperlukan untuk INT_MAX dan INT_MIN
#include <float.h>    // Diperlukan untuk FLT_MAX (untuk inisialisasi rata-rata terendah)

int main() {
    int n;           // Variabel untuk menyimpan jumlah angka yang akan dimasukkan
    int angka;       // Variabel untuk menyimpan setiap angka yang dimasukkan
    int min_val = INT_MAX; // Inisialisasi nilai minimum dengan nilai integer terbesar yang mungkin
    int max_val = INT_MIN; // Inisialisasi nilai maksimum dengan nilai integer terkecil yang mungkin

    float min_avg_consecutive = FLT_MAX; // Inisialisasi rata-rata terendah dengan nilai float terbesar
    int prev_angka = 0; // Menyimpan angka sebelumnya untuk perhitungan rata-rata berturut-turut
    int is_first_avg_pair = 1; // Flag untuk menentukan apakah ini pasangan rata-rata pertama

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
            float current_avg = (float)(prev_angka + angka) / 2.0;

            // Membandingkan dengan rata-rata terendah yang ditemukan sejauh ini
            if (is_first_avg_pair || current_avg < min_avg_consecutive) {
                min_avg_consecutive = current_avg;
                is_first_avg_pair = 0; // Rata-rata pertama sudah diinisialisasi
            }
        }
        prev_angka = angka; // Simpan angka saat ini untuk digunakan sebagai 'prev_angka' di iterasi berikutnya
    }

    // Menampilkan hasil nilai terkecil dan terbesar
    printf("%d\n", min_val);
    printf("%d\n", max_val);

    // Menampilkan rata-rata terendah jika ada cukup data (n >= 2)
    if (n >= 2) {
        printf("%.2f\n", min_avg_consecutive);
    } else {
        // Opsional: Pesan jika tidak ada cukup angka untuk rata-rata
        // printf("Tidak cukup angka untuk menghitung rata-rata pasangan.\n");
    }

    return 0; // Mengindikasikan program berhasil dieksekusi
}
