#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;

struct Node{

    int data;
    Node *left      = NULL;
    Node *right     = NULL;
    Node *nextRight = NULL;
    Node( int data ) {
        this -> data = data;
    }
};


void connectRecur( Node *p ) {

    if( p == NULL )
        return;

    if( p -> left != NULL )
        p -> left -> nextRight = p -> right; // will be set to NULL if not present

    if( p -> right != NULL )
        p -> right -> nextRight = ( p -> nextRight ) ? p -> nextRight -> left : NULL;

    connectRecur( p -> left  );
    connectRecur( p -> right );
}

void connect( Node *root ) {

    root -> nextRight = NULL;
    connectRecur( root );

}

int main() {

    Node *root        = new Node(10);
    root->left        = new Node(8);
    root->right       = new Node(2);
    root->left->left  = new Node(3);

    connect(root);


    return 0;

}


