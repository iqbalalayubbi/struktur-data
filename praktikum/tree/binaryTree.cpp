#include <iostream>
#include <string>

using namespace std;


struct Mahasiswa{
    int npm;
    string nama;
    int height; // selisih sub tree kiri sama substree kanan
    Mahasiswa *left;
    Mahasiswa *right;
};

struct Tree{
    int value;
    Tree *left;
    Tree *right;
};

Tree *root, *newTree;

Tree *createTree(int value){
    root = new Tree();
    root->value = value;
    root->left = NULL;
    root->right = NULL;
    return root;
}

Tree *insertLeft(int value, Tree *parent){
    newTree = new Tree();
    newTree->value = value;
    newTree->left = NULL;
    newTree->right = NULL;
    if (parent->left == NULL){
        parent->left = newTree;
    }
    return newTree;
}

Tree *insertRight(int value, Tree *parent){
    newTree = new Tree();
    newTree->value = value;
    newTree->left = NULL;
    newTree->right = NULL;
    if (parent->right == NULL){
        parent->right = newTree;
    }
    return newTree;
}

void preOrder(Tree *curr){
    if (curr != NULL){
        cout << curr->value << endl;
        preOrder(curr->left);
        preOrder(curr->right);
    }else{
        cout << "jalan" << endl;
    }
}

void inOrder(Tree *curr){
    if (curr != NULL){
        inOrder(curr->left);
        cout << curr->value << endl;
        inOrder(curr->right);
    }else{
        cout << "jalan" << endl;
    }
}

void postOrder(Tree *curr){
    if (curr != NULL){
        postOrder(curr->left);
        postOrder(curr->right);
        cout << curr->value << endl;
    }else{
        cout << "jalan" << endl;
    }
}

bool searchTree(int value){
    Tree *curr = root;
    while(curr != NULL){
        if (value == curr->value) return true;
        if (value < curr->value) curr = curr->left;
        else curr  = curr->right;
    }
    return false;
}

void insertTree(int value){
    Tree *temp = root;
    Tree *newNode = new Tree();
    newNode->value = value;

    if (root == NULL) root = newNode;
    else{
        Tree *temp2;
        while(temp != NULL){
            temp2 = temp;
            if (newNode->value < temp->value) temp = temp->left;
            else temp = temp->right;
        }
        if (newNode->value < temp2->value) temp2->left = newNode;
        else temp2->right = newNode;
    }
}

int main(){
    // Tree *temp1 = createTree(1);
    // Tree *temp2 = insertLeft(2, temp1);
    // Tree *temp3 = insertRight(3, temp1);
    insertTree(1);
    insertTree(2);
    insertTree(3);
    insertTree(4);
    insertTree(5);
    insertTree(6);

    bool result = searchTree(5);
    cout << result;
    // preOrder(root);
    // inOrder(temp1);
    // cout << temp1->right->value;
    // g++ binaryTree.cpp -o binaryTree && .\binaryTree
    return 0;
}