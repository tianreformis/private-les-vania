#include <stdio.h>
#include <math.h>

int main(){
    // ! not (|| atau ) (&& dan)
    int A,B;
    A = 9; 
    B = 10;
    if (A==B && A<=B){
        printf("true");
    }
    else {
        printf("false");
    }
    return 0;
}