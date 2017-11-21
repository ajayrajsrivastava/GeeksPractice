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

int height( Node *root ) {

    if( root == NULL )
        return 0;

    int lh = height( root -> left  );
    int rh = height( root -> right );

    return max(lh,rh) + 1;

}

void printKDistance(Node *root, int k)
{

    // AC without edge case ie k > h on practice
    int h = height(root);
    if( k > h)
        return;


    if( root == NULL )
        return;

    if( k == 0 )
        cout << root -> data << " ";

    if( k > 0) {

        printKDistance( root -> left , k-1 );
        printKDistance( root -> right, k-1 );

    }


}

int main( ) {


    Node *root        = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(8);

    printKDistance(root, 2);


    return 0;
}






