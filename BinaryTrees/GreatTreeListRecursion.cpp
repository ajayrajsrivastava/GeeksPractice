#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

//Stanford CS109
//http://cslibrary.stanford.edu/109/TreeListRecursion.html

struct Node {

    int data;
    Node* small = NULL;
    Node* large = NULL;

    Node(int data) {

        this -> data = data;

    }
};


void join(Node *a,Node *b) {

    a -> large = b;
    b -> small = a;

}

//appends two circular doubly linked list
Node* append( Node *a,Node *b )
{
    Node *aLast;
    Node *bLast;

    if( a == NULL )     return  b;
    if( b == NULL )     return  a;

    aLast = a -> small;
    bLast = b -> small;

    join(aLast, b);
    join(bLast, a);

    return a;
}

Node* treeToList(Node* root) {

    Node *aList;
    Node *bList;

    if( root == NULL )      return NULL;

    aList = treeToList( root -> small );
    bList = treeToList( root -> large );

    // Make length - 1 list
    root -> small = root;
    root -> large = root;

    aList = append(aList,root);
    aList = append(aList,bList);

    return aList;
}

//print circular doubly linked list
void printList( Node *head ) {

    Node *curr = head;

    while( 1 )
    {
        cout << curr -> data << " ";
        curr = curr  -> large;

        if( curr == head)   break;
    }

}

//builds tree
void treeInsert( Node** ref, int data ) {

    Node *root = *ref;
    if( root == NULL )
        *ref = new Node(data);
    else
    {
        if( data <= root -> data )
            treeInsert( &( root -> small ), data );
        else
            treeInsert( &( root -> large ), data );
    }

}

int main() {


    Node *root   = NULL;
    Node *head;

    treeInsert(&root,4);
    treeInsert(&root,2);
    treeInsert(&root,1);
    treeInsert(&root,3);
    treeInsert(&root,5);

    head = treeToList(root);
    printList(head);

    return 0;

}

