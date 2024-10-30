#include <stdio.h>
int main(){
    int a,b,result;
    //and (&) or (|), xor(^), not(~), << geser kiri, geser kanan >>
    a=3;
    int result_geser_kiri=a<<2;
    printf("%d\n",result_geser_kiri);

    a=3;
    int result_geser_kanan=a>>2;
    printf("%d\n",result_geser_kanan);
    //1 1 2 3 3 7

    a=4;
    b=5;
    int result_and= a & b;
    printf("%d\n",result_and);

    a=4;
    b=5;
    int result_or= a | b;
    printf("%d\n",result_or);

    a=4;
    b=5;
    int result_xor= a ^ b;
    printf("%d\n",result_xor);




}