#include<iostream>
#include<cstdio>
using namespace std;

struct Node{

    int data;
    Node *left  = NULL;
    Node *right = NULL;
    Node *nextRight = NULL;

    Node( int data ) {

        this -> data = data;
    }
};


Node* getNextRight( Node * p ) {


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

void connect( Node *p ) {


    //p for level
    //q for nodes

    if( p == NULL )
        return;

    p -> nextRight = NULL;
    // root


    while( p != NULL ) {


        Node *q = p;

        while( q != NULL ) {

            if( q -> left != NULL ) {

                if( q -> right != NULL )
                    q -> left -> nextRight = q -> right;

                else
                    q -> left -> nextRight = getNextRight(q);
            }

            if( q -> right != NULL )
                q -> right -> nextRight = getNextRight(q);

            q = q -> nextRight;
        }

        if( p -> left != NULL )
            p = p -> left;

        else if( p -> right != NULL )
            p = p -> right;

        else
            p = getNextRight(p);
    }

}

int main() {

/*
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
*/

    Node *root        = new Node(10);
    root->left        = new Node(8);
    root->right       = new Node(2);
    root->left->left  = new Node(3);
    root->right->right= new Node(90);

    // Populates nextRight pointer in all nodes
    connect(root);

    return 0;

}
