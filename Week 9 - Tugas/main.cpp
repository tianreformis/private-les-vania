#include <stdio.h> 
#include <stdlib.h> 

typedef struct Node { 
    int id; 
    struct Node *next;
} Node; 

typedef struct { 
    Node *front, *rear; 
} Que; 

Que *createQue() { 
    Que *newQue = (Que*)malloc(sizeof(Que)); 
    newQue->front = newQue->rear = NULL; 
    return newQue; 
}

void pushQue(Que *s, int id) { 
    Node *newNode = (Node*)malloc(sizeof(Node)); 
    newNode->id = id; 
    newNode->next = NULL; 

    if (s->front == NULL) { 
        s->front = s->rear = newNode; 
    } else { 
        s->rear->next = newNode; 
        s->rear = newNode; 
    }
}

int popQue(Que* s) {
    if (s->front == NULL) {
        return -1; // antrian kosong atau -1
    } 

    Node* temp = s->front;
    int id = temp->id;

    s->front = s->front->next;
    if (s->front == NULL) {
        s->rear = NULL; // jika antrian kosong
    }

    free(temp);
    return id;
}

Que* mergeQue(Que* s1, Que* s2) { 
    Que* mix = createQue(); 
    
    while (s1->front || s2->front) { 
        if (s1->front) pushQue(mix, popQue(s1)); 
        if (s2->front) pushQue(mix, popQue(s2));  
    }

    return mix; 
}

void cancelQue(Que* s, int cancel) { 
    Node* temp = s->front;
    Node* prev = NULL;

    // check baian depan apakah bisa di batalkan atau tidak
    if (temp != NULL && temp->id == cancel) {
        s->front = temp->next;

        // jika antrial kosong update depannya
        if (s->front == NULL) {
            s->rear = NULL;
        }
        free(temp);
        return; 
    }

    
    while (temp != NULL && temp->id != cancel) {
        prev = temp;
        temp = temp->next;
    }

    // error mu disini harusnya null bukan 0, krn  struct bukan primitive integer
    if (temp == NULL) { 
        return;
    }


    prev->next = temp->next;


    if (temp == s->rear) {
        s->rear = prev; 
    }

    free(temp); 
} 

void displayQue(Que* s) {
    Node* curr = s->front;
    while (curr) {
        printf("%d ", curr->id);
        curr = curr->next;
    }
    printf("\n");
}

int main() { 
    int walk; 
    int onl; 
    int cancel; 

    Que* walkQue = createQue(); 
    Que* onlQue = createQue(); 

    scanf("%d", &walk); 
    scanf("%d", &onl); 
    scanf("%d", &cancel); 

    for (int i = 0; i < walk; i++) { 
        int idWalk; 
        scanf("%d", &idWalk); 
        pushQue(walkQue, idWalk);
    }
    
    for (int i = 0; i < onl; i++) { 
        int idOnline; 
        scanf("%d", &idOnline); 
        pushQue(onlQue, idOnline); 
    }

    Que* mix = mergeQue(walkQue, onlQue);

    for (int i = 0; i < cancel; i++) { 
        int idCancel; 
        scanf("%d", &idCancel); 
        cancelQue(mix, idCancel);
    }
    
    displayQue(mix); 

    
    while (mix->front != NULL) {
        popQue(mix);
    }
    free(mix);
    
    
    free(walkQue);
    free(onlQue);

    return 0; 
}