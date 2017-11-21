#include<iostream>
#include<stdlib.h>
using namespace std;

struct node {

    int data;
    struct node *left;
    struct node *right;
    bool rightThreaded;
};

struct node *newNode( int data ) {

struct node *node = (struct node*)malloc(sizeof( struct node));
node -> data  = data;
node -> left  = NULL;
node -> right = NULL;

return node;

}

struct node* leftmost( struct node *root) {

    if( root == NULL )  return NULL;

    while( root -> left != NULL ) {
        root = root -> left;
    }

    return root;
}

void inorder( struct node *root ) {

    struct node *curr = leftmost(root);

    while( curr != NULL ) {

        cout << curr -> data << " ";
        if( curr -> rightThreaded )
        {

            curr  = curr -> right;
        }
        else
        {
            curr = leftmost( curr -> right );

        }

    }

}

int main() {

    struct node *root  = newNode(6);
    struct node *root3 = newNode(3); root -> left  = root3;
    struct node *root8 = newNode(8); root -> right = root8;

    root -> left -> left  = newNode(1);
    root -> left -> right = newNode(5);

    root -> right -> left =  newNode(7);
    struct node *root11   = newNode(11);root -> right -> right = root11;

    root -> right -> right -> right = newNode(13);
    root -> right -> right -> left  = newNode(9);

    // Creating threded BT
    root -> left  -> left  -> right =  root3;
    root -> left  -> right -> right =  root;
    root -> right -> left  -> right =  root8;
    root -> right -> right -> left  -> right = root11;

    root -> left  -> left  -> rightThreaded = true;
    root -> left  -> right -> rightThreaded = true;
    root -> right -> left  -> rightThreaded = true;
    root -> right -> right -> left -> rightThreaded = true;

    inorder(root);
    return 0;

}
