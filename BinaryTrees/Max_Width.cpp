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

int width( Node *root ) {

    if( root == NULL )
        return 0;


    queue<Node *>q1,q2;
    q1.push( root );
    int mw = 1;

    while( 1 ) {


        while( !q1.empty() ) {

            Node *temp = q1.front();q1.pop();

            if( temp -> left != NULL )
                q2.push( temp -> left );

            if( temp -> right != NULL )
                q2.push( temp -> right );

        }

        int q2size = q2.size();
        mw = max(mw,q2size);

        while( !q2.empty() ) {

            Node *temp = q2.front();q2.pop();

            if( temp -> left != NULL )
                q1.push( temp -> left );

            if( temp -> right != NULL )
                q1.push( temp -> right );

        }

         int q1size = q1.size();
         mw = max(q1size,mw);

        if( q1size == 0 && q2size == 0 )
            break;
    }


    return mw;
}
//AC

int main( ) {


    Node *root        = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);

    cout << width( root ) << endl;


    return 0;
}


