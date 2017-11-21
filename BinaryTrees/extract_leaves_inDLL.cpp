#include<iostream>
#include<cstdlib>
using namespace std;

struct Node {

    int data;
    Node *left  = NULL;
    Node *right = NULL;

    Node( int data ) {

        this -> data = data;
    }

};



void inorder( Node *root ) {

    if( root == NULL )
        return ;

     inorder( root -> left ) ;
     cout  << root -> data << " ";
     inorder( root -> right );

}


Node* extractLeaf( Node *root, Node **head_ref ) {

    if( root == NULL )
        return NULL;



    if( root -> left == NULL && root -> right == NULL )
    {

        root -> right = (*head_ref);

        if( (*head_ref) != NULL )
            (*head_ref) -> left = root;

        (*head_ref) = root;

        return NULL;
    }

    root -> right = extractLeaf( root -> right, head_ref );
    root -> left  = extractLeaf( root -> left , head_ref );

    return root;
}

void printList( Node *head ) {

    while( head != NULL ){

        cout << head -> data << " ";
        head = head -> right;
    }

}

int main() {

     Node *root = new Node(1);
     root->left = new Node(2);
     root->right = new Node(3);
     root->left->left = new Node(4);
     root->left->right = new Node(5);
     root->right->right = new Node(6);
     root->left->left->left = new Node(7);
     root->left->left->right = new Node(8);
     root->right->right->left = new Node(9);
     root->right->right->right = new Node(10);

     Node *head = NULL;

     inorder(root);

     root = extractLeaf( root, &head );

     cout << "\n";

     inorder(root);

     cout << "\n";

     printList(head);

    return 0;
}



