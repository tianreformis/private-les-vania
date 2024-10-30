#include <stdio.h>
#include <math.h>


int kemungkinan_menang(int N) {
    // Menghitung total kemungkinan hasil pertandingan
    int total_kemungkinan = pow(2, N);
    // Menghitung kemungkinan menang setidaknya sekali
    int kemungkinan_menang_setidaknya_sekali = total_kemungkinan - 1;
    return kemungkinan_menang_setidaknya_sekali;
}

int main() {
    int N;
    // Input jumlah tim musuh
    scanf("%d", &N);
    // Mendapatkan hasil
    if (N < 0 || N> 50){
        return 1;
    }
    int hasil = kemungkinan_menang(N);
    // Output hasil
    printf("%d\n", hasil);
    return 0;
}