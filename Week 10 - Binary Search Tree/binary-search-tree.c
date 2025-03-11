#include <stdio.h>
#include <stdlib.h>

// Struktur node BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Fungsi untuk membuat node baru
struct Node* buatNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Fungsi untuk memasukkan node
struct Node* insert(struct Node* root, int data) {
    if(root == NULL) {
        return buatNode(data);
    }
    if(data < root->data) {
        root->left = insert(root->left, data);
    }
    else if(data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Fungsi untuk traversal inorder
void inorderTraversal(struct Node* root) {
    if(root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Fungsi pencarian node
struct Node* search(struct Node* root, int data) {
    if(root == NULL || root->data == data)
        return root;
    if(data < root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

// Fungsi untuk menghapus node
struct Node* deleteNode(struct Node* root, int data) {
    if(root == NULL) return root;
    
    if(data < root->data)
        root->left = deleteNode(root->left, data);
    else if(data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        // Node dengan satu anak atau tanpa anak
        if(root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        
        // Node dengan dua anak: cari penerus inorder (nilai terkecil di subtree kanan)
        struct Node* temp = root->right;
        while(temp->left != NULL)
            temp = temp->left;
        
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    
    // Membangun BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    // Traversal inorder (hasil terurut)
    printf("Traversal inorder: ");
    inorderTraversal(root);
    printf("\n");
    
    // Pencarian node
    int cari = 60;
    struct Node* hasil = search(root, cari);
    if(hasil != NULL)
        printf("Node %d ditemukan\n", cari);
    else
        printf("Node %d tidak ditemukan\n", cari);
    
    // Menghapus node
    root = deleteNode(root, 20);
    printf("Setelah menghapus 20: ");
    inorderTraversal(root);
    printf("\n");
    
    return 0;
}
