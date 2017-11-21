#include<iostream>
#include<stack>
using namespace std;

//Idea is to use an explicit stack
//Push right child then left child of popped item until stack is not empty

struct Node{

    int data;
    Node *left = NULL;
    Node *right = NULL;

    Node( int data ) {

        this -> data = data;
    }

};


void iterativePreorder( Node *root ) {

    if( root == NULL )
        return ;


    stack < Node * > nodeStack;
    nodeStack.push ( root ) ;

    while( ! nodeStack.empty() ) {

        Node *temp = nodeStack.top();
        cout << temp -> data << " ";
        nodeStack.pop();


        if( temp -> right != NULL )
            nodeStack.push ( temp -> right );

        if( temp -> left != NULL )
            nodeStack.push ( temp -> left );

    }

}


int main() {

  Node *root        = new Node(10);
  root->left        = new Node(8);
  root->right       = new Node(2);
  root->left->left  = new Node(3);
  root->left->right = new Node(5);
  root->right->left = new Node(2);

  iterativePreorder(root);
  return 0;

}
