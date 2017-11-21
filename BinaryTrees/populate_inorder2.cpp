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

void populateNextRecur( Node *p, Node **next_ref ) {

    if( p == NULL )
        return;

    populateNextRecur( p -> right, next_ref );

    p -> next = *next_ref;
    *next_ref  = p;

    populateNextRecur( p -> left, next_ref );
}

void populateNext( Node *root ) {

    Node *next = NULL;

    populateNextRecur(root,&next);

}

int main() {


    Node *root        = new Node(10);
    root->left        = new Node(8);
    root->right       = new Node(12);
    root->left->left  = new Node(3);

    //doesn't uses static var
    populateNext(root);

    return 0;

}
