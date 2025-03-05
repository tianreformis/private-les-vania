#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10  // Ukuran hash table

// Struktur node untuk linked list (digunakan untuk chaining)
typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

// Hash table dengan array of pointers ke linked list
Node* hashTable[TABLE_SIZE];

// Fungsi Hash (menggunakan modulo)
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Fungsi untuk menambahkan elemen ke hash table
void insert(int key, int value) {
    int index = hashFunction(key);
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    // Jika tidak ada elemen di index ini, langsung tambahkan
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        // Collision: Tambahkan di awal linked list
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
}

// Fungsi untuk mencari nilai berdasarkan key
int search(int key) {
    int index = hashFunction(key);
    Node* temp = hashTable[index];

    while (temp) {
        if (temp->key == key) {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1;  // Key tidak ditemukan
}

// Fungsi untuk menghapus elemen dari hash table
void delete(int key) {
    int index = hashFunction(key);
    Node* temp = hashTable[index];
    Node* prev = NULL;

    while (temp) {
        if (temp->key == key) {
            if (prev == NULL) {
                hashTable[index] = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Key %d dihapus.\n", key);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Key %d tidak ditemukan.\n", key);
}

// Fungsi untuk menampilkan isi hash table
void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        Node* temp = hashTable[i];
        while (temp) {
            printf("(%d, %d) -> ", temp->key, temp->value);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Program utama
int main() {
    insert(1, 10);
    insert(11, 20);
    insert(21, 30);
    insert(2, 40);
    insert(12, 50);

    printf("Isi Hash Table:\n");
    display();

    printf("\nMencari key 11: %d\n", search(11));
    printf("Mencari key 5: %d\n", search(5));  // Tidak ditemukan

    printf("\nMenghapus key 11:\n");
    delete(11);
    display();

    return 0;
}
