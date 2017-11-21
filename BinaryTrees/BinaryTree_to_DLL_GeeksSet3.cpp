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

    static Node *pre = NULL;

    if( root == NULL )      return ;

    tree2List( root -> left ,head );

    if( pre == NULL )
        *head = root;
    else {

        root -> left  = pre;
        pre  -> right = root;
    }
    pre  = root;

    tree2List( root -> right ,head );
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

    Node *head = NULL;
    tree2List( root,&head );

    printList(head);

    return 0;
}


