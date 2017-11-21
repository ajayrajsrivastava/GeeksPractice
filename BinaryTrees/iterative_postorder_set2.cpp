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

    stack<Node *> s;

    Node *curr = root;
    s.push(root);

    while(!s.empty()) {

        if( curr -> left != NULL )
        {
            curr = curr -> left;
            s.push(curr);
        }

        else if( curr -> right != NULL)
        {

            curr = curr -> right;
            s.push(curr);
        }

        else {

            curr = s.top();
            s.pop();
            cout << curr -> data << " ";
            curr = s.top();
        }

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




