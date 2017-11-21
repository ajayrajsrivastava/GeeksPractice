//http://www.geeksforgeeks.org/convert-a-binary-tree-to-a-circular-doubly-link-list/

#include<iostream>
#include<stdlib.h>

using namespace std;


struct Node {

    int data;
    Node *left  = NULL;
    Node *right = NULL;

    Node( int data ) {

        this -> data = data;
    }

};


Node *concatenate( Node *leftList, Node *rightList ) {

    if( leftList  == NULL )
        return rightList;

    if( rightList == NULL )
        return leftList;

    Node *leftLast  = leftList  -> left;
    Node *rightLast = rightList -> left;

    //join(leftLast,rightList);
    leftLast  -> right = rightList;
    rightList -> left  = leftLast;

    //join(leftList,rightLast);
    leftList  -> left  = rightLast;
    rightLast -> right = leftList;

    return leftList;
}



Node* bTreeToCList( Node *root ) {

    if( root == NULL )  return NULL;

    Node *left  = bTreeToCList( root -> left  );
    Node *right = bTreeToCList( root -> right );

    root -> left = root -> right = root;

    return concatenate(concatenate(left,root),right);
}

void displayCList(Node *head) {

    Node *curr = head;
    do {

        cout << curr -> data << " ";
        curr = curr -> right;
    }
    while( head != curr );

}


int main() {

    Node *root        = new Node(10);
    root->left        = new Node(12);
    root->right       = new Node(15);
    root->left->left  = new Node(25);
    root->left->right = new Node(30);
    root->right->left = new Node(36);

    Node *head = bTreeToCList(root);
    displayCList(head);


    return 0;
}
