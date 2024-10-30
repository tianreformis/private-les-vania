/*
2 = biner
8 = oktal 
10 = desimal (bilangan bulat)
16 = heksadesimal hex hexadecimal
0 .. f
0 1 2 .. 9 10 (a), 11(b), 12(c), 13 (d), 14(e), 15(f)
0 .. 9 10 (a) 11(b), 15(f)
%d decimal &o octal &b binary &x hex
*/

#include <stdio.h>
int main(){
   int N;
    scanf("%d",&N); //masukkan integer (desimal)
    printf("%x\n",N); //%x hexadsimal
    return 0;
}