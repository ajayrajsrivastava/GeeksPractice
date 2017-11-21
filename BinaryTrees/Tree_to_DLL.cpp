#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node {

    int data;
    Node *left  = NULL;
    Node *right = NULL;

    Node(int data) {

        this -> data = data;
    }

};

Node* join( Node *a,Node *b ) {

    a -> right = b;
    b -> left  = a;

    return a;
}

Node* append( Node *a,Node *b ) {

    Node *aLast;

    if( a == NULL )     return b;
    if( b == NULL )     return a;

    aLast = a;
    while( aLast -> right != NULL ) {
        aLast = aLast -> right;
    }


    join(aLast,b);

    return a;
}


Node* treeToList( Node *root ) {

    Node *aList;Node *bList;

    if( root == NULL )  return NULL;

    aList = treeToList( root -> left  );
    bList = treeToList( root -> right );

    // make 1-node list

    root -> left  = NULL;
    root -> right = NULL;

    aList = append(aList,root);
    aList = append(aList,bList);

    return aList;
}


void printList( Node *head ) {

    while( head != NULL ) {

        cout << head -> data << " ";
        head = head -> right;
    }

}

int main() {

    Node *root           = new Node(1);

    root->left           = new Node(2);
    root->right          = new Node(3);
    root->left->left     = new Node(4);
    root->left->right    = new Node(5);

    Node *head = treeToList(root);
    printList(head);

    return 0;

}
