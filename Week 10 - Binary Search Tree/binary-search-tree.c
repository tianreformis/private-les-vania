#include <stdio.h>
#include <stdlib.h>
//struct 
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
//membuat node baru
struct Node* buatNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL; 
        return newNode;
        /* data */    
}
//memasukkan data node 
struct Node* insert(struct Node* root, int data){
    //kalau data kosong, memulai node
    if (root ==  NULL){
        return buatNode(data);
    }
    //data akan diisi dari kiri 
    if (data < root->data){
        root->left = insert(root->left,data);
    } 
    //kalau data kiri sudah diisi akan geser kanan
    else if (data > root->data){
        root->right = insert(root->right,data);
    }    
    //return
    return root;
}

//transversal inorder (urutan data)
void inorderTransversal(struct Node* root){
    if (root != NULL){
        inorderTransversal(root->left);
        printf("%d ", root->data);
        inorderTransversal(root->right);
    }
}

//function pencarian node
struct Node* search(struct Node* root, int data){
    //kalau data kosong, memulai node
    if (root ==  NULL || root->data == data){
        return root;
    }
    if (data < root->data){
        return search(root->left, data);
    }
    else{
        return search(root->right, data);
    }
}

//function delete node 
struct Node* delete(struct Node* root, int data){
    //kalau data kosong, memulai node
    if (root ==  NULL) return root;
    
    if (data < root->data){
        root ->left = delete(root->left, data);
    } else if (data > root->data){
        root ->right = delete(root->right, data);
    }
    else{
        if (root->left == NULL){
            struct Node* temp =root->right;
            free(root);
            return temp;
        } 
        else if(root->right == NULL){
            struct Node* temp =root->left;
            free(root);
            return temp;
        }
        struct Node* temp = root->right; //menunjuk bagian kanan dari root, disimpan kedalam tempoprary variabel
        while (temp->left != NULL) //untuk mencari node terkecil di tree 
            temp = temp->left; //node terkecil ditemukan dan dia disalin (succersor in order)
        root->data = temp->data;
        root->right = delete(root->right, temp->data); //node dihapus

    }
    return root;
}
//main function

int main(){
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    inorderTransversal(root);

    int cari = 60;
    struct Node* result = search(root, cari);
    if (result != NULL){
        printf("\nData %d ditemukan di dalam tree", cari);
    } 
    else {
        printf("\nData %d tidak ditemukan di dalam tree", cari);
    }
    //menghapus node r
    // root = delete(root, 20);    
    // printf("Setelah menghapus 20 : ");
    // inorderTransversal(root);
    // printf("\n");
    return 0;
}