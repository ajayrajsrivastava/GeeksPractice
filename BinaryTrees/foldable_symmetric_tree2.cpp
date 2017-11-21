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

    if( a == NULL && b != NULL )
        return false;

    if( a != NULL && b == NULL )
        return false;

    if( isStructSame( a -> left, b -> left) && isStructSame( a -> right, b -> right ) )
        return true;
}

bool isFoldableUtil( Node *root1, Node *root2 ) {


    if( root1 == NULL && root2 == NULL )
        return true;

    if( root1 == NULL || root2 == NULL )
        return false;

    return isFoldableUtil( root1 -> left, root2 -> right ) && isFoldableUtil( root1 -> right, root2 -> left );

}

bool isFoldable( Node *root ) {



    if( root == NULL )
        return true;

   return isFoldableUtil( root -> left, root -> right );
   //check left and right subtree are mirror images

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





