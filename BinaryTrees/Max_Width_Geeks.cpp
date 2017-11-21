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

int getWidth( Node *root, int level ) {

    if( root == NULL )
        return 0;


    if( level == 1 )
        return 1;

    else if( level > 1 )
        return getWidth( root -> left, level - 1 ) + getWidth( root -> right, level - 1 );

}


int getMaxWidth( Node *root ) {

    int maxw = 0;

    for( int i = 1; i < height(root); i++ ) {

        int w = getWidth(root,i);
        maxw  = max(maxw,w);
    }

    return maxw;
}


int main( ) {


    Node *root                 = new Node(1);
    root->left                 = new Node(2);
    root->right                = new Node(3);
    root->left->left           = new Node(4);
    root->left->right          = new Node(5);
    root->right->right         = new Node(8);
    root->right->right->left   = new Node(6);
    root->right->right->right  = new Node(7);

    cout << "Maximum width is " << getMaxWidth(root) ;

    return 0;
}



