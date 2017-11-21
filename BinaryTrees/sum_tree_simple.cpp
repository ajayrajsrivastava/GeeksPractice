#include<iostream>
#include<stack>
using namespace std;

struct Node{

    int data;
    Node *left  = NULL;
    Node *right = NULL;

    Node( int data ) {

        this -> data = data;
    }
};


int sum( Node *root ) {

    if( root == NULL )
        return 0;

    return root -> data + sum( root -> left ) + sum( root -> right );

}

bool isSumTree( Node *root ) {


    if( root == NULL || (root -> left == NULL && root -> right == NULL) )
        return true;

    else {

        int left  = 0;
        int right = 0;

        if( root -> left  != NULL )
            left  = sum(root -> left);  // sum of left subtree

        if( root -> right != NULL )
            right = sum(root -> right); //sum of right subtree


        if( (left + right) == root -> data && isSumTree( root -> left ) && isSumTree( root -> right) )
            return true;
        else
            return false;
    }

}


int main() {


    Node *root         = new Node(26);
    root->left         = new Node(10);
    root->right        = new Node(3);
    root->left->left   = new Node(4);
    root->left->right  = new Node(6);
    root->right->right = new Node(3);


    if( isSumTree(root) )
        cout << "The given tree is a SumTree ";
    else
        cout << "The given tree is not a SumTree ";


}

