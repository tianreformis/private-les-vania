#include <stdio.h>
#include <string.h>

int main(){
    char nama[50]="Vania";
    char gelar[50]=" S.Kom";
    // printf("Masukkan Nama = ");
    // fgets(nama, sizeof(nama), stdin);
    // printf("Masukkan Gelar = ");
    // fgets(gelar, sizeof(gelar), stdin);
    strcat(nama,gelar);
    printf("%s\n",nama);


    return 0;
}