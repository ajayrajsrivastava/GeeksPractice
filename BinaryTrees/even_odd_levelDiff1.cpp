#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct  Node{

    int data;
    Node *left  = NULL;
    Node *right = NULL;
    Node( int data ) {
        this -> data = data;
    }
};



int getLevelDiff( Node* root ) {

    if( root == NULL )
        return 0;



    return (root -> data) - getLevelDiff( root -> left ) - getLevelDiff( root -> right );
}


int main() {

    Node *root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left  = new Node(1);
    root->left->right = new Node(4);
    root->left->right->left = new Node(3);
    root->right->right = new Node(8);
    root->right->right->right = new Node(9);
    root->right->right->left = new Node(7);

    cout << "Diff : ";

    cout << getLevelDiff(root);

    return 0;
}

