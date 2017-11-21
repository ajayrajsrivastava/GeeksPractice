#include<iostream>
#include<stdlib.h>
using namespace std;

struct node {

    int data;
    struct node *left;
    struct node *right;
};


int size( struct node *root) {

    if ( root == NULL )
        return 0;
    else
        return ( size( root -> left) + size( root -> right) + 1 );

}

struct node* newNode ( int data ) {

    struct node *node = (struct node *)malloc( sizeof( struct node) );
    node -> data  = data;
    node -> left  = NULL;
    node -> right = NULL;

    return node;
}

int main() {

  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);

  cout << "size - " << size(root) ;
  return 0;

}
