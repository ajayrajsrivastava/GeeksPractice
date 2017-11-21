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



bool solve( Node *node, int sum ) {


    if( node == NULL )
        return ( sum == 0);

    else {


        bool ans = 0;

        int subSum = sum - node -> data;

        if( subSum == 0 && node -> left == NULL && node -> right == NULL )
            return 1;

        // or used since return 1 if any of the left or right subtree path contains given sum

        if( node -> left  != NULL )
            ans = ans || solve( node -> left, subSum );

        if( node -> right != NULL )
            ans = ans || solve( node -> right, subSum );


        return ans;
    }

}


int main( ) {


    Node *root        = new Node(10);
    root->left        = new Node(8);
    root->right       = new Node(2);
    root->left->left  = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(2);

    int sum = 21;


    if( solve(root,sum) )
        cout << "There is a root-to-leaf path with sum " << sum;
    else
        cout << "There is no root-to-leaf path with sum " << sum;

    return 0;
}
