#include<iostream>
using namespace std;

struct Node {

    int data;
    Node *left = NULL;
    Node *right = NULL;

    Node( int data ) {

        this -> data = data;
    }

};

int search( int arr[], int start, int end ) {

    int maxIndex = start;
    int maxElem  = arr[maxIndex];

    for( int i = start + 1; i <= end; i++ ) {

        if( arr[i] > maxElem ){

            maxElem  = arr[i];
            maxIndex = i;
        }

    }

    return maxIndex;
}

Node* buildTree( int inorder[], int startIndex, int endIndex ) {

    if( startIndex > endIndex )
        return NULL;

    int inIndex = search( inorder, startIndex, endIndex );
    Node *root = new Node( inorder[inIndex] );

    if( startIndex == endIndex )
        return root;

    root -> left  = buildTree( inorder, startIndex, inIndex - 1 );
    root -> right = buildTree( inorder, inIndex + 1, endIndex   );

    return root;
}


void printInorder( Node *root ) {

    if( root == NULL )
        return;

    printInorder( root -> left );
    cout << root -> data << " ";
    printInorder( root -> right );


}

int main() {

    // O(n^2) approach can be minimised using Segment Trees
    int inorder[] = {5, 10, 40, 30, 28};
    int len = sizeof(inorder)/sizeof(inorder[0]);
    Node *root = buildTree(inorder, 0, len - 1);

    printInorder( root );
}
