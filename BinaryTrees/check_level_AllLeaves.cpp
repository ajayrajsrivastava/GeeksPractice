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

bool solve( Node *root, int level, int *leafLevel ) {

    if( root == NULL )
        return true;

    if( root -> left == NULL && root -> right == NULL )
    {
        if( *leafLevel == 0 ) // FIRST LEAF NODE
        {
            *leafLevel = level;
            return true;
        }

        return ( level == (*leafLevel) );
    }

    return solve( root -> left, level + 1, leafLevel ) && solve( root -> right, level + 1, leafLevel ) ;

}

bool check( Node *root ) {

    int level     = 0;
    int leafLevel = 0;

    return solve( root, level, &leafLevel );

}


int main() {

    Node *root = new Node(12);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(9);
    root->left->left->left = new Node(1);
    root->left->right->left = new Node(1);

    cout << check(root);

    return 0;
}

