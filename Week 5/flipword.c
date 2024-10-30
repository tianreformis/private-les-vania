#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char input[MAX];
    char *words[MAX];
    int count = 0;

    printf("Masukkan input: ");
    fgets(input, MAX, stdin);

    // Menghapus newline di akhir input
    input[strcspn(input, "\n")] = '\0';

    // Memisahkan kata-kata
    char *token = strtok(input, " ");
    while (token != NULL) {
        words[count++] = token; // Simpan pointer ke kata
        token = strtok(NULL, " ");
    }

    // Mencetak kata-kata dalam urutan terbalik
    printf("Output: ");
    for (int i = count - 1; i >= 0; i--) {
        printf("%s", words[i]);
        if (i != 0) {
            printf(" "); // Tambahkan spasi antar kata
        }
    }
    printf("\n");

    return 0;
}