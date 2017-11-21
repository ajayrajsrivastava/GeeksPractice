#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;


struct Node{

    int data;
    Node *left  = NULL;
    Node *right = NULL;
    Node( int data ) {
        this -> data = data;
    }
};


bool solve( Node *root, int &maxh, int &minh ) {

    if( root == NULL ) {

        maxh = 0;
        minh = 0;
        return true;
    }

    //FOR LEFT & RIGHT SUB
    int lmaxh,lminh;
    int rmaxh,rminh;

    // IF ANY SUBTREE NOT BALANCED
    if( solve( root -> left, lmaxh, lminh) == false )
        return false;

    if( solve( root -> right, rmaxh, rminh) == false )
        return false;

    maxh = max( lmaxh, rmaxh ) + 1;
    minh = min( lminh, rminh ) + 1;

    if( maxh <= 2 * minh )
        return true;

    return false;
}


bool isBalanced( Node *root ) {

    int maxh;
    int minh;

    return solve( root, maxh, minh );
}


int main() {

    Node * root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(100);
    root->right->left = new Node(50);
    root->right->right = new Node(150);
    root->right->left->left = new Node(40);
    isBalanced(root)? cout << "Balanced" : cout << "Not Balanced";

    return 0;

}

