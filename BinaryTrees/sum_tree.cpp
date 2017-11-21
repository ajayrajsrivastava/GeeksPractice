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

bool isLeaf( Node *root ) {


    if( root -> left == NULL && root -> right == NULL )
        return true;

    return false;
}

bool isSumTree( Node *root ) {

    int left,right;

    if( root == NULL || isLeaf(root) )
        return true;


    if( isSumTree( root -> left ) && isSumTree( root -> right) ) {

        if( root -> left == NULL )
            left = 0;

        else if( isLeaf( root -> left) )
            left = root -> left -> data;

        else
            left = 2*( root -> left -> data);



        if( root -> right == NULL )
            right = 0;

        else if( isLeaf( root -> right) )
            right = root -> right -> data;

        else
            right = 2*( root -> right -> data);


        return (root -> data == left + right );

    }

    return false;
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

    return 0;

}

