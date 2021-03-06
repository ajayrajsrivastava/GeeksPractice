#include<iostream>
#include<cstdlib>
using namespace std;


struct Node {

    int data;
    Node *left  = NULL;
    Node *right = NULL;
    Node *next  = NULL;

    Node( int data )
    {
        this -> data = data;
    }
};


void populateNext( Node *root ) {


    static Node *next = NULL;
    //next of rightmost node will be null

    // Reverse Inorder Traversal

    if( root == NULL )
        return;


    populateNext( root -> right );

    root -> next = next;
    next = root;

    populateNext( root -> left );

}

int main() {


    Node *root        = new Node(10);
    root->left        = new Node(8);
    root->right       = new Node(12);
    root->left->left  = new Node(3);

    // Populates nextRight pointer in all nodes
    populateNext(root);

    return 0;

}
