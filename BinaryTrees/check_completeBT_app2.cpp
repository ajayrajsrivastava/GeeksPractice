#include<iostream>
using namespace std;

struct Node{

    int data;
    Node *left = NULL;
    Node *right = NULL;

    Node( int data ) {

        this -> data = data;

    }

};

int countNodes( Node *root ) {

    if( root == NULL )
        return 0;

    return ( 1 + countNodes( root -> left) + countNodes( root -> right ) );

}

bool isComplete( Node* root, int index, int node_count ) {


    if( root == NULL )
        return true;

    if( index >= node_count )
        return false;

    return ( isComplete( root -> left, 2 * index + 1, node_count ) && isComplete( root -> left, 2 * index + 2, node_count ) );
}

int main() {

    Node *root         = new Node(1);
    root->left         = new Node(2);
    root->right        = new Node(3);
    root->left->left   = new Node(4);
    root->left->right  = new Node(5);
    root->right->right = new Node(6);

    int node_count = countNodes( root );
    int index      = 0;

    if( isComplete( root, index, node_count ) )
        cout << "Binary Tree is Complete" << endl;
    else
        cout << "Binary Tree is not Complete" << endl;

    return 0;
}
