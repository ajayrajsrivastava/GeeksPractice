#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

const int N = 10000;

struct Node{

    int data;
    Node *left  = NULL;
    Node *right = NULL;
    Node( int data ) {
        this -> data = data;
    }
};


void solve( Node *root, int path[], bool vis[], int pathLen, int k ) {

    if( root == NULL )
        return;


    path[ pathLen ] = root -> data;
    vis [ pathLen ] = false;
    pathLen++;


    if( root -> left == NULL && root -> right == NULL && pathLen - k - 1 >= 0 && vis[ pathLen - k - 1 ]  == false ) {

        cout << path[ pathLen - k - 1 ] << " ";
        vis[ pathLen - k - 1 ] = true;
        return;
    }

    solve( root -> left,  path, vis, pathLen, k );
    solve( root -> right, path, vis, pathLen, k );

}

void printKDistantfromLeaf( Node *root, int k ) {

    int  path[ N ];
    bool vis [ N ] = { false };

    solve( root, path, vis, 0, k );
}


int main() {

    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);

    cout << "Nodes at distance 2 are: ";
    printKDistantfromLeaf(root, 2);

    return 0;

}

