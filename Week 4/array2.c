#include <stdio.h>

int main(){
    char array[10]={"1"};
    int matriks[2][3];
    char kelas[200] = "Kelas 12";

//         0 1 2
//  0  2 3 4
//  1  5 6 5
    matriks[0][0]=2;
    matriks[0][1]=3;
    matriks[0][2]=4;
    printf("%d\n",array[0]);

    int i,j;
    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            printf("%d \n",matriks[i][j]);
        }
    }
}