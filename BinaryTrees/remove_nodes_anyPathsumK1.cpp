#include<iostream>
#include<cstdlib>
using namespace std;

struct Node {

    int data;
    Node *left  = NULL;
    Node *right = NULL;

    Node( int data ) {

        this -> data = data;
    }

};



void inorder( Node *root ) {

    if( root == NULL )
        return ;

     inorder( root -> left ) ;
     cout  << root -> data << " ";
     inorder( root -> right );

}


Node* prune( Node *root, int sum, int k ) {

    if( root == NULL )
        return NULL;

    root -> left  = prune ( root -> left,  sum + root -> data, k );
    root -> right = prune ( root -> right, sum + root -> data, k );

    if( root -> left == NULL && root -> right == NULL )
    {

        if( root -> data + sum < k ) {

            free( root );
            return NULL;
        }

    }

    return root;
}

int main() {

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(12);
    root->right->right->left = new Node(10);
    root->right->right->left->right = new Node(11);
    root->left->left->right->left = new Node(13);
    root->left->left->right->right = new Node(14);
    root->left->left->right->right->left = new Node(15);


    inorder(root);

    root = prune( root, 0, 45 );
    cout << "\n";

    inorder(root);

    return 0;
}



