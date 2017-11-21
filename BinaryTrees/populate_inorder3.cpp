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

    static Node *prev = NULL;

    if( root == NULL )
        return;

    populateNext( root -> left );

    if( prev != NULL ) {

        prev -> next = root;

    }

    prev = root;

    populateNext( root -> right );


}

int main() {


    Node *root        = new Node(10);
    root->left        = new Node(8);
    root->right       = new Node(12);
    root->left->left  = new Node(3);

    //uses simple inorder traversal
    populateNext(root);

    return 0;

}
