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

Node* solve_inPlace( Node* root ) {

    if( root == NULL )  return NULL;

    if( root -> left != NULL ) {


        Node *left  = solve_inPlace( root -> left );

        //Get Inorder Predecessor
        while( left -> right != NULL )
            left = left -> right;

        left -> right = root;
        root -> left  = left;
    }

    if( root -> right != NULL ) {

        Node *right = solve_inPlace( root -> right );

        //Get Inorder Succesor

        while( right -> left != NULL )
            right = right -> left;

        right -> left  = root;
        root  -> right = right;
    }

    return root;
}


Node* tree2List( Node *root ) {

    Node* last = solve_inPlace( root );

    while( last -> left != NULL ) {

        last = last -> left;

    }

    Node *head = last;

    return head;

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
