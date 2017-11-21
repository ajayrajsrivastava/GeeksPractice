#include<iostream>
#include<queue>
#include<stdlib.h>
using namespace std;

struct Node {

    int data;
    Node *left  = NULL;
    Node *right = NULL;

    Node( int data ) {

        this -> data = data;
    }
};





void printInorder( Node *root ) {


    if( root == NULL )
        return;

    printInorder( root -> left ) ;
    cout << root -> data << " " ;
    printInorder( root -> right );

}


void doubleTree( Node *root ) {

    if( root == NULL )
        return;


    doubleTree( root -> left );
    doubleTree( root -> right );

    Node *oldLeft  = root -> left ;
    root -> left   = new Node( root -> data );
    root -> left -> left = oldLeft;
}


int main( ) {


    Node *root        = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);

    cout << "Inorder traversal of the original tree is \n";
    printInorder(root);

    doubleTree(root);

    cout << "\nInorder traversal of the double tree is \n";
    printInorder(root);


    return 0;
}

