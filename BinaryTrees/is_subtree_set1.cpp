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

Node* findKey( Node *root , int key ) {

    Node *r1 = NULL;
    Node *r2 = NULL;

    if( root == NULL )
        return NULL;

    if( root -> data == key )
        return root;

    r1 = findKey( root -> left , key );
    r2 = findKey( root -> right, key );

    if( r1 != NULL )
        return r1;

    if( r2 != NULL )
        return r2;
}

bool checkSame(Node *root1, Node *root2) {

    if( root1 == NULL && root2 == NULL )
        return true;

    if( root1 == NULL || root2 == NULL )
        return false;

    bool c1 = checkSame( root1 -> left,  root2 -> left  );
    bool c2 = checkSame( root1 -> right, root2 -> right );

    return ( root1 -> data == root2 -> data ) && c1 && c2;
}


bool isSubTree(Node *T,Node *S) {


    if( T == NULL )
        return false;

    if( S == NULL )
        return true;


    Node *root1 = findKey(T,S -> data);
    Node *root2 = S;

    if( root1 == NULL )
        return false;
    else
        return checkSame(root1,root2);

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

