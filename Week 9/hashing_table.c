#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//struct
typedef struct Node {
    int key;
    int value;
    struct Node* next;
}Node;

//hash tabel dengan array of pointer ke linklist 
Node* hashTable[MAX];

//functions hash
int HashFunction(int key){
    return key % MAX;
}
//function tambah elemen
//function cari element
//function hapus

//function tampilkna data


//main function
int main(){

}