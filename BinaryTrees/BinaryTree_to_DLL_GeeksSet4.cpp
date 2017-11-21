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

//inplace inorder tree to DLL
void tree2List( Node *root,Node **head ) {

    if( root == NULL )  return;

    tree2List( root -> right,head );

    root -> right = *head;

    if( *head != NULL )
        (*head) -> left = root;

    *head = root;

    tree2List( root -> left,head );

}

void printList( Node *head ) {

    while( head != NULL ) {

        cout << head -> data << " ";
        head = head  -> right;

    }

}

int main() {

    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->right = new Node(8);
    root->left->left->left = new Node(0);
    root->left->left->right = new Node(2);
    root->right->right->left = new Node(7);
    root->right->right->right = new Node(9);

    Node *head = NULL;
    tree2List( root,&head );

    printList(head);

    return 0;
}



