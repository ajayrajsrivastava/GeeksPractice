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


void getMaxWidthRecur( Node *root, int count[], int level ) {

    if( root != NULL ) {

        count[level]++;
        getMaxWidthRecur( root -> left,  count, level + 1 );
        getMaxWidthRecur( root -> right, count, level + 1 );

    }


}


int getMaxWidth( Node *root ) {

    int h = height( root );
   // 1.intialise count array
   // 2.count[] = {0};
    int *count = new int[h];
    int level  = 0;

    //3.Do Preorder traversal and fill array
    getMaxWidthRecur( root, count, level );

    int maxx = -1;
    for( int i = 0; i < h; i++ ) {
        maxx = max( count[i],maxx );
    }

    return maxx;

}

//using Preorder Traversal

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




