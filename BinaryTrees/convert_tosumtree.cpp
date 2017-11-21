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

    int left,right;

    if( root == NULL )
        return 0;

    if( root -> left == NULL && root -> right == NULL ) {

        int val = root -> data;
        root -> data = 0; // leaf node
        return val;

    }

    left  = toSumTree( root -> left  );
    right = toSumTree( root -> right );

    int sum = left + right;
    int val = root -> data;

    root -> data = sum;

    return (sum + val);
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

    // AC on Practice..

    toSumTree(root);
    printInorder(root);

    return 0;
}
