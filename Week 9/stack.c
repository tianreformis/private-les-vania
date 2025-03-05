#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maksimum kapasitas stack

// Struktur stack
typedef struct {
    int top;
    int array[MAX];
} Stack;

// Inisialisasi stack
void init(Stack *s) {
    s->top = -1;
}

// Periksa apakah stack kosong
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Periksa apakah stack penuh
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Push elemen ke stack
void push(Stack *s, int data) {
    if (isFull(s)) {
        printf("Stack overflow!\n");
        return;
    }
    s->array[++(s->top)] = data;
}

// Pop elemen dari stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow!\n");
        return -1;
    }
    return s->array[(s->top)--];
}

// Mengintip elemen teratas stack
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack kosong!\n");
        return -1;
    }
    return s->array[s->top];
}

// Menampilkan seluruh elemen dalam stack
void show(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack kosong!\n");
        return;
    }
    printf("Stack: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->array[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Sebelum pop:\n");
    show(&s);
    pop(&s);
    printf("Setelah pop:\n");
    show(&s);
    return 0;
}
