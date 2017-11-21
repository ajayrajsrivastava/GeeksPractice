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


Node * getNextRight( Node *p ) {

    Node *temp = p -> nextRight;

    while( temp != NULL ) {

        if( temp -> left != NULL )
            return temp -> left;

        if( temp -> right != NULL )
            return temp -> right;

        temp = temp -> nextRight;
    }

    return NULL;
}

void connectRecur( Node *p ) {


    if( p == NULL )
        return;

    cout << p -> data << " ";

    if( p -> nextRight != NULL )
        connectRecur( p -> nextRight );



    if( p -> left != NULL ) {

        if( p -> right != NULL ) {
            p -> left  -> nextRight = p -> right;
            p -> right -> nextRight = getNextRight(p);
        }

        else
            p -> left -> nextRight = getNextRight(p);

        connectRecur( p -> left );
    }
    else if( p -> right != NULL ){

        p -> right -> nextRight = getNextRight(p);
        connectRecur( p -> right );

    }
    else {

        connectRecur( getNextRight(p) );
    }

}

void connect( Node *root ) {

    root -> nextRight = NULL;
    connectRecur( root );

}

int main() {

    Node *root                = new Node(1);

    root->left                = new Node(2);
    root->right               = new Node(3);

    root->left->left          = new Node(4);
    root->left->right         = new Node(5);
    root->right->left         = new Node(6);
    root->right->right        = new Node(7);

    root->left->left->left    = new Node(8);
    root->left->left->right   = new Node(9);
    root->right->right->left  = new Node(10);
    root->right->right->right = new Node(11);



    connect(root);


    return 0;

}



