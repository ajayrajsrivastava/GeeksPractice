#include<iostream>
#include<queue>
#include<stdlib.h>
using namespace std;

struct Node {

    int data;
    Node *left  = NULL;
    Node *right = NULL;

    Node( int data ) {

        this -> data = data;
    }
};

void mirror( Node* root ) {

    if( root == NULL )
        return;

    mirror( root -> left );
    mirror( root -> right );
    swap( root -> left, root -> right );

}

bool isStructSame( Node *a, Node *b ) {

    if( a == NULL && b == NULL )
        return true;

    if( a == NULL || b == NULL )
        return false;

    if( isStructSame( a -> left, b -> left) && isStructSame( a -> right, b -> right ) )
        return true;
}


bool isFoldable( Node *root ) {

    bool res;

    if( root == NULL )
        return true;

    mirror( root -> left );

    res = isStructSame( root -> left, root -> right );

    mirror( root -> right );

    return res;
}





int main( ) {


    Node *root        = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->right->left = new Node(4);
    root->left->right = new Node(5);

    if( isFoldable(root) == 1)
        cout << "tree is foldable";
    else
        cout << "tree is not foldable";


    return 0;
}





