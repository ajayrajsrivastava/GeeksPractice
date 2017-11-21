#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct  Node{

    int data;
    Node *left  = NULL;
    Node *right = NULL;
    Node( int data ) {
        this -> data = data;
    }
};



void reverseLevelOrder( Node* root ) {

    stack <Node *> S;
    queue <Node *> Q;

    Q.push( root );


    while( !Q.empty() ) {

        Node *root = Q.front();
        S.push(root);
        Q.pop();

        if( root -> right != NULL )
            Q.push( root -> right );

        if( root -> left != NULL )
            Q.push( root -> left );

    }

    while( !S.empty() )
    {
        cout << S.top() -> data << " ";
        S.pop();
    }

}


int main() {

    Node *root         = new Node(1);
    root->left         = new Node(2);
    root->right        = new Node(3);
    root->left->left   = new Node(4);
    root->left->right  = new Node(5);
    root->right->left  = new Node(6);
    root->right->right = new Node(7);

    cout << "Reverse Level Order traversal of binary tree is \n";
    reverseLevelOrder(root);

    return 0;
}
