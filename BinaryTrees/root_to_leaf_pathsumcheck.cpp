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


//primary logic is to use parameterised queue instead of
//declaring a  global queue

bool ans = 0;

void checkSum( queue<Node *>q,int sum ) {

    int s = 0;
    while( !q.empty()) {

        s += q.front() -> data;
        q.pop();

    }

    if( sum == s )
        ans = 1;
}

void solve( Node *root,queue<Node*> q,int sum) {

    if( root == NULL )
        return;

    q.push(root);

    if( root -> left == NULL && root -> right == NULL )
        checkSum(q,sum);

    else
    {
        solve( root  -> left  , q, sum);
        solve( root  -> right , q, sum);
    }

}

int main( ) {


    Node *root           = new Node(1);
    root->left           = new Node(2);
    root->right          = new Node(3);
    root->left->left     = new Node(4);
    root->left->right    = new Node(5);

    int sum = 8;

    queue<Node*> q;
    solve(root,q,sum);
    cout << ans << endl;

    return 0;
}
