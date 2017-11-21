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

int c = 0;
void solve( struct node *root) {

    if( root == NULL )
        return;



    if( root -> left == NULL && root -> right == NULL )
        c++;

    else {

        solve( root  -> left  );
        solve( root  -> right );
    }

}


int main( ) {


    struct node *root    = newNode(1);
    root->left           = newNode(2);
    root->right          = newNode(3);
    root->left->left     = newNode(4);
    root->left->right    = newNode(5);

    solve(root);

    cout << c << endl;

    return 0;
}
