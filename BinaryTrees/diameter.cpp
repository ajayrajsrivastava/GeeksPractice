#include<iostream>
#include<queue>
#include<stdlib.h>
using namespace std;

struct node {

    int data;
    struct node *left;
    struct node *right;

};

struct node* newNode( int data ) {

    struct node *node = (struct node *) malloc( sizeof( struct node) );
    node -> data  = data;
    node -> left  = NULL;
    node -> right = NULL;


    return node;
}

int height( struct node *root) {

    if( root == NULL )
        return 0;

    int hl = height( root -> left  );
    int hr = height( root -> right );


    return max(hl,hr) + 1;

}

int diameter( struct node* root ) {

    if( root == NULL )
        return 0;


    int hl = height( root -> left  );

    int hr = height( root -> right );

    return hl + hr + 1;

}

int main( ) {


    struct node *root    = newNode(1);
    root->left           = newNode(2);
    root->right          = newNode(3);
    root->left->left     = newNode(4);
    root->left->right    = newNode(5);

    cout << diameter(root) << endl;

    //logic used diameter = height of LS + height of RS

    //wrong approach....
    // since not considered diameter of left subtree and right subtree

    return 0;
}

