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


bool isSumProperty( Node *root ) {

    //empty tree or single leaf node
    if( root == NULL || (root -> left == NULL && root -> right == NULL) )
        return true;

    else {

        int left  = 0;
        int right = 0;

        if( root -> left  != NULL )
            left = root -> left -> data;

        if( root -> right != NULL )
            right = root -> right -> data;


        if( (left + right) == root -> data && isSumProperty( root -> left) && isSumProperty( root -> right) )
            return true;
        else
            return false;
    }

}


int main() {

    Node *root         = new Node(10);
    root->left         = new Node(8);
    root->right        = new Node(2);
    root->left->left   = new Node(3);
    root->left->right  = new Node(5);
    root->right->right = new Node(2);

    if(isSumProperty(root))
        cout << "The given tree satisfies the children sum property ";
    else
        cout << "The given tree does not satisfy the children sum property ";


    return 0;

}

