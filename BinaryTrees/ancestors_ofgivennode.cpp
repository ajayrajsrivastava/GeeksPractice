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

bool printAncestors( Node *root, int key ) {


    if( root == NULL )
        return false;

    if( root -> data == key ) {
        return true;
    }

    if( printAncestors( root -> left  , key ) || printAncestors( root -> right , key ) )
    {
        cout << root -> data << " ";
        return true;
    }

    return false;
}

int main( ) {


    Node *root        = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left  = new Node(7);


    printAncestors(root, 7 );
    cout << endl;

    return 0;
}







