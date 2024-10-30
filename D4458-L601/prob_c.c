#include <stdio.h>

int main() {
    int N, Q, i, Ai, Bi;
    scanf("%d", &N);
    int prices[N];

    //for untuk harga awal
    //1 2 3 4 5 6 ++i 
    //0 1 2 3 4 5 6 i++ 7
    for (i = 0; i < N; i++) {
        scanf("%d", &prices[i]);
    }
    //for untuk perubahan harga
    scanf("%d", &Q);
    for (i = 0; i < Q; i++) {
        scanf("%d %d", &Ai, &Bi);
        prices[Ai - 1] = Bi;//refactoring array 
        //0 1 2 3 4 5 6 i++ 7
        //0 1 2 3 4 5 6 
    }

    for (i = 0; i < Q; i++) {
        printf("Case #%d: ", i + 1);
        for (int j = 0; j < N; j++) {
            printf("%d", prices[j]);
            if (j < N - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}