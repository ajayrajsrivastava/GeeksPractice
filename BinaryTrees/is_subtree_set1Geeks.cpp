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

bool areIdentical( Node *root1, Node *root2 ) {

    if( root1 == NULL && root2 == NULL )
        return true;

    if( root1 == NULL || root2 == NULL )
        return false;

    return ( root1 -> data == root2 -> data ) && areIdentical( root1 -> left, root2 -> left ) && areIdentical( root1 -> right, root2 -> right );
}

bool isSubTree(Node *T,Node *S) {

    if( S == NULL )
        return true;


    if( T == NULL )
        return false;


    if( areIdentical(T,S) ) // O(m) m is no of nodes in S
        return true;

    else
        return isSubTree( T -> left, S ) || isSubTree( T -> right, S ); // O(n)

}


int main() {

    Node *T               = new Node(26);
    T->right              = new Node(3);
    T->right->right       = new Node(3);
    T->left               = new Node(10);
    T->left->left         = new Node(4);
    T->left->left->right  = new Node(30);
    T->left->right        = new Node(6);

    Node *S               = new Node(10);
    S->right              = new Node(6);
    S->left               = new Node(4);
    S->left->right        = new Node(30);


    if (isSubTree(T, S))
        cout << "Tree 2 is subtree of Tree 1";
    else
        cout << "Tree 2 is not a subtree of Tree 1";

    return 0;

}

