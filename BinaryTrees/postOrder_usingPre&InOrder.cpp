#include<iostream>
using namespace std;

struct Node {

    int data;
    Node *left  = NULL;
    Node *right = NULL;

    Node( int data ) {

        this -> data = data;
    }

};

int search( int arr[], int start, int end, int key ) {

    for( int i = start; i <= end; i ++ ) {

        if( arr[i] == key )
            return i;

    }

}
Node* solve( int in[], int post[], int inStart, int inEnd, int *pIndex ) {

    if( inStart > inEnd )
        return NULL;

    Node *tNode = new Node( post[*pIndex] );
    (*pIndex)--;

    if( inStart == inEnd ) //no children ie leaf
        return tNode;

    int inIndex = search(in, inStart, inEnd, tNode -> data );

    tNode -> right = solve( in, post, inIndex + 1, inEnd     , pIndex );
    tNode -> left  = solve( in, post, inStart,     inIndex - 1 , pIndex );

    return tNode;
}

void preOrder(Node* node)
{
    if (node == NULL) return;
    cout << node -> data << " ";
    preOrder(node->left);
    preOrder(node->right);
}


Node *buildTree( int in[], int post[], int n ) {

    int pIndex = n - 1;
    return solve(in, post, 0, n - 1, &pIndex );

}
int main() {

    int  in[]   = {4, 8, 2, 5, 1, 6, 3, 7};
    int  post[] = {8, 4, 5, 2, 6, 7, 3, 1};

    int n = 8; // length;

    Node *root = buildTree(in, post, n);
    preOrder(root);

    return 0;
}

