#include<iostream>
#include<map>
using namespace std;


struct Node {

    int data;
    Node *left  = NULL;
    Node *right = NULL;

    Node( int data ) {

        this -> data = data;

    }
};


void verticalSum( Node *root, int hd ) {

    static map<int,int>sum;

    if( root == NULL )
        return;

    verticalSum( root -> left, hd - 1 );
    sum[hd] += root -> data;
    verticalSum( root -> right, hd + 1 );

}

int main() {

    Node *root         = NULL;

    root               = new Node(1);
    root->left         = new Node(2);
    root->right        = new Node(3);
    root->left->left   = new Node(4);
    root->left->right  = new Node(5);
    root->right->left  = new Node(6);
    root->right->right = new Node(7);


    verticalSum(root,0);
    // AC on Practice..

    return 0;
}
