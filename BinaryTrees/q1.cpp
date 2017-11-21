#include<iostream>
using namespace std;

struct Node{

    int data;
    Node *left  = NULL;
    Node *right = NULL;

    Node( int data ) {
        this -> data = data;
    }
};

Node *constructTreeUtil( int pre[], int post[], int *preIndex, int l, int h, int size ) {

    //Base Case
    if( (*preIndex) >= size || l > h )
        return NULL;


    Node *root = new Node( pre[(*preIndex)] );
    (*preIndex)++;

    if( l == h )
        return root;

    //Search next elem of pre[] in post[]

    int i;
    for( i = l; i <= h; i++ )
        if( pre[ (*preIndex) ] == post[i] )
            break;

    if( i <= h ) {

        root -> left  = constructTreeUtil( pre, post, preIndex, l, i, size );
        root -> right = constructTreeUtil( pre, post, preIndex, i+1, h, size );
    }

    return root;
}


void inorder( Node *root ) {

    if ( root == NULL )
        return;

    inorder( root -> left );
    cout << root -> data << " ";
    inorder( root -> right );

}

Node *constructTree( int pre[], int post[], int size ) {

    int preIndex = 0;
    return constructTreeUtil( pre, post, &preIndex, 0, size - 1, size );
}

int main() {

    int pre[]  = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};

    int size = sizeof(pre)/sizeof(pre[0]);

    Node *root = constructTree( pre, post, size );

    inorder(root);

    return 0;
}
