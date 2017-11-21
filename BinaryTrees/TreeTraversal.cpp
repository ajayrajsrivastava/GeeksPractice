#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct node {

    int data;
    struct node* left;
    struct node* right;

};

struct node* newNode(int data) {

    struct node* node = (struct node*) malloc(sizeof (struct node));
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;

    return node;
}

void printPreorder( struct node* root) {

    if( root == NULL )
        return;

    printf("%d ",root->data);
    printPreorder(root->left);
    printPreorder(root->right);

}

void printInorder( struct node* root) {

    if( root == NULL )
        return;

    printInorder(root->left);
    printf("%d ",root->data);
    printInorder(root->right);

}

void printPostorder( struct node* root) {

    if( root == NULL )
        return;


    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d ",root->data);

}


int main() {


    struct node* root    = newNode(1);
    root->left           = newNode(2);
    root->right          = newNode(3);
    root->left->left     = newNode(4);
    root->left->right    = newNode(5);

    printf("PreOrder Traversal : \n");
    printPreorder(root);
    printf("\n");

    printf("InOrder Traversal : \n");
    printInorder(root);
    printf("\n");

    printf("PostOrder Traversal : \n");
    printPostorder(root);
    printf("\n");

    return 0;

}
