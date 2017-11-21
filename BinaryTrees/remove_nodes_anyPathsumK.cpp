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

Node* solve( Node *root, int k, int *sum ) {

    if( root == NULL )
        return NULL;

    //INITIALIZE LEFT & RIGHT SUM = SUM FROM ROOT TO THIS NODE
    int lsum = (*sum) + root -> data;
    int rsum = lsum;

    root -> left  = solve( root -> left,  k, &lsum );
    root -> right = solve( root -> right, k, &rsum );

    (*sum) = max( lsum, rsum );

    if( (*sum) < k )
    {
        free(root);
        root = NULL;
    }

    return root;
}

Node* prune( Node *root, int k ) {

    int sum = 0;
    return solve( root, k, &sum );

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

    root = prune( root, 45 );
    cout << "\n";

    inorder(root);

    return 0;
}



