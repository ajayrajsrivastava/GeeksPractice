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

void solve( Node *root, int level, int *maxLevel ) {

    if( root == NULL )
        return;

    if( level > *maxLevel )
    {
        cout << root -> data << " ";
        *maxLevel = level;

    }

    solve( root -> left,  level + 1, maxLevel );
    solve( root -> right, level + 1, maxLevel ) ;

}

void leftView( Node *root ) {


    int maxLevel = 0;

    solve( root, 1, &maxLevel );

}


int main() {

    Node *root = new Node(12);
    root->left = new Node(10);
    root->right = new Node(30);
    root->right->left = new Node(25);
    root->right->right = new Node(40);

    leftView(root);

    return 0;
}


