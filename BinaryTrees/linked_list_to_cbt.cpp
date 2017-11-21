#include<iostream>
#include<queue>
using namespace std;

struct Node{

    int data;
    Node *left  = NULL;
    Node *right = NULL;

    Node( int data )
    {
        this -> data = data;
    }

};

struct ListNode{

    int data;
    ListNode *next = NULL;

    ListNode( int data ) {

        this -> data = data;
    }

};


void push( ListNode** head_ref, int data ) {

    ListNode *new_node = new ListNode( data );
    new_node -> next = ( *head_ref );

    ( *head_ref ) = new_node;
}

//Alias passed for root of Tree
void convertList2Binary( ListNode *head, Node* &root ) {

    queue< Node* > q;

    if( head == NULL ) {

        root = NULL;
        return;
    }

    //FIRST NODE
    root = new Node( head -> data );
    q.push( root );

    head = head -> next;

    while( head != NULL ) {

        Node *par = q.front();
        q.pop();

        Node *leftChild  = NULL;
        Node *rightChild = NULL;

        leftChild = new Node( head -> data );
        q.push( leftChild );

        head = head -> next;

        if( head != NULL ) {

            rightChild = new Node( head -> data );
            q.push( rightChild );
            head = head -> next;

        }

        par -> left  = leftChild;
        par -> right = rightChild;
    }

}


void inorderTraversal( Node *root ) {

    if( root == NULL )
        return;

    inorderTraversal( root -> left );
    cout << root -> data << " ";
    inorderTraversal( root -> right );


}
int main() {


    ListNode* head = NULL;

    push(&head, 36);  /* Last node of Linked List */
    push(&head, 30);
    push(&head, 25);
    push(&head, 15);
    push(&head, 12);
    push(&head, 10); /* First node of Linked List */

    Node *root = NULL;
    convertList2Binary(head, root);

    cout << "Inorder Traversal of the constructed Binary Tree is: \n";
    inorderTraversal(root);

    return 0;
}
