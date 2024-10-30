#include <stdio.h>
#include <string.h>

int main(){
    char nama[50]="Prodi Computer Science"; 
    char *hasil;

    hasil = strstr(nama,"Science");    //konsep and
    
    printf("%s\n",hasil);


    return 0;
}