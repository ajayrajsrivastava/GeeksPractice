#include<iostream>
#include<stdlib.h>
using namespace std;

struct node {

    int data;
    struct node *left;
    struct node *right;

};


struct node* newNode ( int data ) {

    struct node *node = ( struct node *) malloc( sizeof( struct node ) ) ;
    node -> data  = data;
    node -> left  = NULL;
    node -> right = NULL;

    return node;
}

void deleteTree( struct node *node ) {

    if( node == NULL )  return;

    deleteTree( node -> left);
    deleteTree( node -> right);

    cout << "Deleting node " << node -> data  << "\n";
    free( node );

    return;
}

int main() {

    // Postorder traversal for deleting tree safely

    struct node *root    = newNode(1);
    root->left           = newNode(2);
    root->right          = newNode(3);
    root->left->left     = newNode(4);
    root->left->right    = newNode(5);

    deleteTree(root);
    root = NULL; // < ------- very important

   cout << "\nTree deleted ";


    return 0;
}
