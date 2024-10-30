#include <stdio.h>
#include <math.h>

int main() {
    double A = 0.0031213123;
    double akar_A = sqrt(A);
    double B = 8;
    double akar_kubik_B = cbrt(B);
    
    printf("%f\n %f\n",akar_A, akar_kubik_B);
    
    //pangkat 
    double C = pow(2,3);
    printf ("%f\n",C);
    
    
    double D = sin(90);
    printf ("%f\n",D);
    double E = tan(90);
    printf ("%f\n",E);
    double F = cos(90);
    printf ("%f\n",F);
    
    //membulatkan kebawah
    double G = floor(12.99);
    double newVar = floor(G);
    printf ("%f\n",G);
    
    //membulatkan keatas
    double H = ceil(12.99);
    printf ("%f\n",H);
    
    //  kebawah <5 >=5 keatas
    double I = round(12.44);
    printf ("%f\n",I);
    //logaritma
    double J = log (12);
    printf ("%f\n",J);
    
}