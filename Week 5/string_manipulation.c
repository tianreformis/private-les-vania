#include <stdio.h>
#include <string.h>

int main(){
    char nama[50];
    printf("Masukkan Nama = ");
    fgets(nama, sizeof(nama), stdin);

    char namabaru[50];

    strcpy(namabaru, nama); //copy string ke namabaru
    int panjang_karakter; //string length

    panjang_karakter = strlen(nama);
    printf("%i",panjang_karakter);
    printf("\n%s",namabaru); //print string namabaru
    printf("\n%s",nama); //

    return 0;
}