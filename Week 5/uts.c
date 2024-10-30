#include <stdio.h>
#include <string.h>

int main() {
    char pesan[301]; // Buffer untuk menyimpan pesan

    // Membaca pesan dari input
    printf("Masukkan pesan yang akan dienkripsi: ");
    fgets(pesan, sizeof(pesan), stdin);

    // Menghapus newline jika ada
    size_t len = strlen(pesan);
    if (len > 0 && pesan[len - 1] == '\n') {
        pesan[len - 1] = '\0';
    }

    // Melakukan enkripsi
    for (char *p = pesan; *p != '\0'; p++) {
        char c = *p;

        // Jika karakter adalah huruf kapital
        if (c >= 'A' && c <= 'Z') {
            if (c > 'W') {
                c = c - 'W' + 'A' - 3;
            } else {
                c = c + 3;
            }
        }
        // Jika karakter adalah huruf kecil
        else if (c >= 'a' && c <= 'z') {
            if (c > 'w') {
                c = c - 'w' + 'a' - 3;
            } else {
                c = c + 3;
            }
        }

        *p = c; // Update karakter yang terenkripsi
    }

    // Menampilkan hasil enkripsi
    printf("Pesan terenkripsi: %s\n", pesan);

    return 0;
}