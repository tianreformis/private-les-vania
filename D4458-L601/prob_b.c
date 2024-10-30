/*
1 5
1 2 3 4 5

6 5
6 7 8 9 10
for 
*/
#include <stdio.h>
int main(){
    int N, M;
    scanf("%d %d",&N,&M);
    for (int i=N; i < N+M; i++){
        printf("%d\n",i);
    }
    return 0;
}
