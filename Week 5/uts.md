# Konsep Enkripsi Caesar

Enkripsi Caesar adalah metode sederhana untuk mengenkripsi teks dengan menggeser setiap huruf dalam pesan dengan sejumlah posisi tertentu dalam alfabet. Misalnya, dengan menggeser setiap huruf sebanyak tiga posisi, huruf A menjadi D, B menjadi E, dan seterusnya. Jika geserannya melebihi huruf Z, maka akan kembali ke awal alfabet.
Penjelasan Baris Kode

    Karakter ASCII:
        Setiap karakter dalam komputer diwakili oleh nilai numerik yang disebut nilai ASCII (American Standard Code for Information Interchange). Misalnya, A memiliki nilai ASCII 65, B adalah 66, dan seterusnya hingga Z yang memiliki nilai 90.

    Baris Kode:

    c

    c = c - 'W' + 'A' - 3;

    Mari kita pecah langkah-langkahnya:

        c - 'W':
            Mengurangi nilai ASCII dari karakter c dengan nilai ASCII dari W (87).
            Ini menghasilkan nilai yang menunjukkan posisi relatif dari c dalam alfabet setelah huruf W.

        + 'A':
            Menambahkan nilai ASCII dari A (65) untuk mengembalikan posisi ke dalam rentang huruf kapital.
            Ini mengubah hasil sebelumnya menjadi nilai ASCII yang sesuai dengan huruf kapital.

        - 3:
            Mengurangi hasilnya dengan 3 untuk melakukan geseran ke belakang (enkripsi).
            Ini memastikan bahwa huruf yang lebih besar dari W (yaitu X, Y, dan Z) akan "meluncur" kembali ke awal alfabet.

Contoh Penggunaan

Misalkan kita memiliki huruf X:

    Hitung:
        c - 'W' → 88 - 87 = 1 (nilai ASCII dari X adalah 88)
        1 + 'A' → 1 + 65 = 66 (hasilnya adalah nilai ASCII dari B)
        66 - 3 → 63 (ini tidak valid, kita akan membahasnya di bawah)

Namun, jika kita ingin hasil yang valid, kita perlu memastikan bahwa kita hanya menggunakan huruf yang tepat.
Penanganan Huruf

Untuk huruf-huruf yang lebih besar dari W (yaitu X, Y, Z), kita perlu menggeser mereka kembali ke awal alfabet:

    Jika c adalah X, maka:
        c - 'W' → 1
        1 + 'A' → 66 (yang merupakan B)
        66 - 3 → 63 (yang tidak valid)

Penanganan Karakter Lain

Untuk huruf yang tidak lebih besar dari W, kita cukup menambahkan 3 ke nilai ASCII-nya:

    Jika c adalah A, maka:
        c + 3 → D (hasil yang valid)

Keseluruhan Proses

    Input Pesan: Program meminta pengguna untuk memasukkan pesan yang akan dienkripsi.
    Iterasi Karakter: Program memeriksa setiap karakter dalam string.
    Penerapan Enkripsi:
        Jika karakter adalah huruf kapital:
            Jika lebih besar dari W, geser kembali ke awal alfabet.
            Jika tidak, cukup tambahkan 3 untuk mengenkripsi.
        Jika karakter adalah huruf kecil, proses serupa dilakukan (dengan penyesuaian untuk huruf kecil).
    Output: Setelah semua karakter dienkripsi, hasilnya ditampilkan.

Kesimpulan

Baris kode c = c - 'W' + 'A' - 3; adalah bagian dari proses enkripsi untuk menangani huruf kapital X, Y, dan Z dalam enkripsi Caesar, memastikan bahwa mereka "meluncur" kembali ke awal alfabet. Proses keseluruhan mencakup pembacaan input, pengolahan setiap karakter, dan output hasil enkripsi. Metode ini adalah cara yang sederhana namun efektif untuk mengenkripsi teks.