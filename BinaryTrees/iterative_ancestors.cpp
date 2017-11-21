#include<iostream>
#include<stack>
using namespace std;


struct Node {

    int  data;
    Node *left;
    Node *right;

    Node( int data ) {

        this -> data = data;
    }
};

void printAncestors( Node *root, int key ) {

    if( root == NULL )
        return;

    stack< Node * > s;


    while( 1 ) {

        //Traverse Left Side

        while( root != NULL && root -> data != key)
        {

            s.push( root );
            root = root -> left;
        }

        //IF FOUND

        if( root != NULL && root -> data == key )
            break;

        //CHECK RIGHT SUBTREE FOR NODE AT TOP OF STACK
        if( s.top() -> right == NULL )
        {

            root = s.top();
            s.pop();

            while( !s.empty() && s.top() -> right == root )
                root = s.top(),s.pop();

        }

        root = s.empty()?NULL : s.top() -> right;
    }


    while( !s.empty() )
    {

        cout << s.top() -> data << " ";
        s.pop();
    }


}

//Assumes given key is present in tree


int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->right->right = new Node(9);
    root->right->right->left = new Node(10);

    int key = 7;
    printAncestors( root, key );

    return 0;

}
