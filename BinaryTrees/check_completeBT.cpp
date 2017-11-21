#include<iostream>
#include<queue>
using namespace std;

struct Node{

    int data;
    Node *left  = NULL;
    Node *right = NULL;
    Node( int data ) {

        this -> data = data;
    }

};


void print( queue<Node *> q) {


    while(!q.empty()) {

        cout << q.front() -> data << " ";
        q.pop();
    }

    cout << endl;
}

bool isCompleteBT( Node *root ) {


    if( root == NULL )
        return true;

    bool foundNonFullNode = false;

    queue< Node * > q;
    q.push( root );

    while( ! q.empty() ) {


        Node *temp = q.front();q.pop();



        if( temp -> left != NULL ) {

            if( foundNonFullNode == true )
                return false;

            q.push( temp -> left );
        }
        else
            foundNonFullNode = true;


        if( temp -> right != NULL ) {

            if( foundNonFullNode == true )
                return false;

            q.push( temp -> right );
        }
        else
            foundNonFullNode = true;

    }

    return true;

}

int main() {


    Node *root         = new Node(1);
    root->left         = new Node(2);
    root->right        = new Node(3);
    root->left->left   = new Node(4);



    if ( isCompleteBT(root) == true )
        cout << "Complete Binary Tree";
    else
        cout << "NOT Complete Binary Tree";

    return 0;

}

