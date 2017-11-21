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


int MaxWidth( Node *root ) {

    if( root == NULL )
        return 0;

    int res = 0;

    queue<Node *> q;
    q.push( root );

    while( !q.empty() ) {


        int count = q.size();
        res = max(count,res);

        while( count -- ) {

            Node *temp = q.front();q.pop();

            if( temp -> left != NULL )
                q.push( temp -> left );

            if( temp -> right != NULL )
                q.push( temp -> right );
        }
    }


    return res;
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

    cout << "Maximum width is " << MaxWidth(root) ;

    return 0;
}



