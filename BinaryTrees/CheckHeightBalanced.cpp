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

int check( struct node* root ) {

    if( root == NULL )
        return 1;

    else {


        int lh = height( root -> left );
        int rh = height( root -> right );
        int diff = abs(lh-rh);

        if( diff > 1)
            diff = 0;
        else
            diff = 1;

        return ( diff && check( root -> left ) && check(root -> right) );
    }

}

int main( ) {


    struct node *root    = newNode(1);
    root->left           = newNode(2);
    root->right          = newNode(3);
    root->left->left     = newNode(4);
    root->left->right    = newNode(5);

    cout << check(root) << endl;

    // runs correctly on practice...
    // complexity O(n^2)

    return 0;
}


