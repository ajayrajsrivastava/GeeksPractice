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

int height( Node *root) {

    if( root == NULL )
        return 0;

    int hl = height( root -> left  );
    int hr = height( root -> right );


    return max(hl,hr) + 1;

}

bool isBalanced( Node* root ) {

    if( root == NULL )
        return 1;

    else {


        int lh = height( root -> left );
        int rh = height( root -> right );
        int diff = abs(lh-rh);

        if( diff<=1 && isBalanced( root -> left ) && isBalanced(root -> right) )
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

    if(isBalanced(root))
      cout << "Tree is balanced";
    else
      cout << "Tree is not balanced";

    //complexity O(n^2)

    return 0;
}



