#include <stdio.h>
#include <stdlib.h>

#define MAX 100
//struct
typedef struct{
    int front,rear;
    int array[MAX];
} Queue;
//init 
void init (Queue *q){
    q->front = -1; //queue koosng tidak ada element didepan
    q->rear = -1; //queue koosng tidak ada element di belakang
}
//check apakah kosong
int isEmpty (Queue *q){
    return q->front == -1;
}
//check apakah penuh
int isFull (Queue *q){
    return q->rear == MAX - 1;
}
//function enqueue
void enqueue (Queue *q, int data){
    if (isFull(q)){
        printf("Queue penuh, data gagal disimpan\n");
        return;
    }
    if (isEmpty(q)){
        q->front = 0;
    }
    q->array[++(q->rear)] = data;
}

//function dequeue
int dequeue (Queue *q){
    if (isEmpty(q)){
        printf("Queue kosong, data gagal diambil\n");
        return -1;
    }
    int data = q->array[q->front];
    if (q->front == q->rear){
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    printf("Data %d diambil\n", data);
}
//function show 
void show (Queue *q){
    if (isEmpty(q)){
        printf("Queue kosong\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++){
        printf("%d ", q->array[i]);
    }
    printf("\n");
}

int main(){
    Queue q;//
    init(&q);
    show(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    show(&q);
    dequeue(&q);
    show(&q);

    return 0;
}