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

int solve( Node *root, int level ) {

    if( root == NULL )
        return 0;

    if( root -> left == NULL && root -> right == NULL && level & 1 )
        return level;

    return max( solve( root -> left, level + 1), solve( root -> right, level + 1 ) );

}

int depthOfOddLeaf( Node *root ) {

    int level = 1;

    return solve( root, level );

}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->right = new Node(7);
    root->right->right->right = new Node(8);
    root->right->left->right->left = new Node(9);
    root->right->right->right->right = new Node(10);
    root->right->right->right->right->left = new Node(11);

    cout << "Depth : " << depthOfOddLeaf( root );

    return 0;
}

