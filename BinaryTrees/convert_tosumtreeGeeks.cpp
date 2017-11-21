#include<iostream>
using namespace std;


struct Node {

    int data;
    Node *left  = NULL;
    Node *right = NULL;

    Node( int data ) {

        this -> data = data;

    }
};


int toSumTree( Node *root ) {


    if( root == NULL )
        return 0;

    int old_val = root -> data;

    root -> data = toSumTree( root -> left ) + toSumTree( root -> right );

    return (root -> data + old_val);
}

void printInorder( Node *root ) {

    if( root == NULL )
        return;

    printInorder( root -> left  );
    cout << root -> data << " ";
    printInorder( root -> right );

}

int main() {

    Node *root         = NULL;

    root               = new Node(10);
    root->left         = new Node(-2);
    root->right        = new Node(6);
    root->left->left   = new Node(8);
    root->left->right  = new Node(-4);
    root->right->left  = new Node(7);
    root->right->right = new Node(5);


    toSumTree(root);
    printInorder(root);

    return 0;
}
