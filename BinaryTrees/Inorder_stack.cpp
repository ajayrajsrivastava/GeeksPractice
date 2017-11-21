#include<iostream>
#include<stack>
using namespace std;


struct node {

    int data;
    struct node *left;
    struct node *right;

};



node* newNode( int data ) {

    node* temp    = new node;
    temp -> data  = data;
    temp -> right = NULL;
    temp -> left  = NULL;

    return temp;

}

void inOrder( node *root ) {

    if ( root == NULL )     return;

    stack<node *>s;
    s.push(root);

    node *temp = root;
    temp = temp -> left;

    while(!s.empty())
    {

        while( temp != NULL ) {

            s.push( temp );
            temp = temp -> left;

        }

        temp = s.top();
        cout << temp -> data << " ";
        s.pop();

        temp = temp -> right;
    }
}

int main() {

    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);

    inOrder(root);

    return 0;
}
