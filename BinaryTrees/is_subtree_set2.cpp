#include<iostream>
using namespace std;

struct Node{

    string data;
    Node *left  = NULL;
    Node *right = NULL;

    Node( string data ) {

        this -> data = data;
    }
};

string inorder( Node *root ) {

    string left,seq,right;

    if( root == NULL )
        return "$";

    left  = inorder( root -> left );
    seq   = left + root -> data;
    right = inorder( root -> right );
    seq = seq + right;

    return seq;
}


string preorder( Node *root ) {

    string seq,left,right;

    if( root == NULL )
        return "$";

    seq   = root -> data;
    left  = preorder( root -> left  );
    seq   = seq + left;
    right = preorder( root -> right );
    seq = seq + right;

    return seq;
}

bool isSubTree(Node *T, Node *S) {

    if( S == NULL )
        return true;

    if( T == NULL )
        return false;

    string inS  = inorder(S);
    string inT  = inorder(T);
    string preS = preorder(S);
    string preT = preorder(T);

    if( inT.find(inS) != string::npos && preT.find(preS) != string::npos ) //if found
        return true;
    else
        return false;

}


int main() {

    Node *T         = new Node("a");
    T->left         = new Node("b");
    T->right        = new Node("d");
    T->left->left   = new Node("c");
    T->right->right = new Node("e");

    Node *S       = new Node("a");
    S->left       = new Node("b");
    S->left->left = new Node("c");
    S->right      = new Node("d");


    if (isSubTree(T, S))
        cout << "Yes: S is a subtree of T";
    else
        cout << "No: S is NOT a subtree of T";

    return 0;

}

