#include<iostream>
using namespace std;

struct node{

    int data;
    struct node* left;
    struct node* right;

};

node* newNode( int data ) {

    node* temp    = new node;
    temp -> data  = data;
    temp -> left  = NULL;
    temp -> right = NULL;

    return temp;
}


int height( node *root ) {

    if( root == NULL )
        return 0;

    int lh = height( root -> left  );
    int rh = height( root -> right );


    return max(lh,rh) + 1;
}

int main() {

    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    cout << height(root);
    return 0;


}
