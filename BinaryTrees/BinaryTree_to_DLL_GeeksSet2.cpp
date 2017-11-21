#include<iostream>
using namespace std;

struct Node {

    int data;
    Node *left  = NULL;
    Node *right = NULL;

    Node( int data ) {

        this -> data = data;
    }
};

void fixLeftPtr( Node *root ) {

    static Node *pre = NULL;

    if( root != NULL ) {

        fixLeftPtr( root -> left );
        root -> left = pre;
        pre = root;
        fixLeftPtr( root -> right );
    }

}

Node* fixRightPtr( Node *root ) {

    static Node *pre = NULL;

    //find last node of DLL/ rightmost node of tree
    while( root -> right != NULL )
        root = root -> right;


    while( root -> left != NULL ) {

        pre = root;
        root = root -> left;
        root -> right = pre;

    }

    return root;
}

Node* tree2List( Node *root ) {

    fixLeftPtr( root );

    return fixRightPtr( root );

}

void printList( Node *head ) {

    while( head != NULL ) {

        cout << head -> data << " ";
        head = head  -> right;

    }

}

int main() {

    Node *root        = new Node(10);
    root->left        = new Node(12);
    root->right       = new Node(15);
    root->left->left  = new Node(25);
    root->left->right = new Node(30);
    root->right->left = new Node(36);

    Node *head = tree2List(root);

    printList(head);

    return 0;
}

