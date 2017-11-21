#include<iostream>
#include<stack>
using namespace std;


struct Node{

    int data;
    Node *left  = NULL;
    Node *right = NULL;

    Node( int data ) {

        this -> data = data;

    }
};




void postOrderIterative( Node *root ) {

    if( root == NULL )
        return;

    stack<Node *> s1,s2;

    s1.push(root);
    Node *temp;

    while(!s1.empty()) {

        temp = s1.top();
        s1.pop();

        s2.push(temp);

        if( temp -> left != NULL )
            s1.push( temp -> left );

        if( temp -> right != NULL )
            s1.push( temp -> right );

    }

    while(!s2.empty()) {

        cout << s2.top() -> data << " ";
        s2.pop();

    }

}

int main() {


    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    postOrderIterative(root);
    return 0;
}



