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

bool isBalanced( Node* root, int *height ) {

    if( root == NULL )
    {
        *height = 0;
        return 1;
    }
    else {

        int lh = 0;
        int rh = 0;

        bool c1 = isBalanced( root -> left,&lh  );
        bool c2 = isBalanced( root -> right,&rh );
        bool c3 = ( abs(lh-rh) <= 1 );

        *height = max(lh,rh) + 1;

        if( c1 && c2 && c3 )
            return true;

        return false;
    }

}

int main( ) {


    Node *root             = new Node(1);
    root->left             = new Node(2);
    root->right            = new Node(3);
    root->left->left       = new Node(4);
    root->left->right      = new Node(5);
    root->left->left->left = new Node(8);

    int height = 0;

    if( isBalanced( root, &height ) )
      cout << "Tree is balanced";
    else
      cout << "Tree is not balanced";

    //complexity O(n)

    return 0;
}



