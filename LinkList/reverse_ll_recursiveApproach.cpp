#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node *newNode( int key ) {
    
    struct node *temp = new node;
    temp -> data = key;
    temp -> next = NULL;
    return temp;

}

void printList(struct node *head) {
    while( head!= NULL ) {
    
        cout << head->data << " " ;
        head = head -> next;
    }

    cout << endl;
}

void reverseUtil( struct node* prev, struct node* curr, struct node** head ) {
    if( curr -> next == NULL ) {
        //last node
        *head = curr;
        curr -> next = prev;
        return;
    }
    struct node *next = curr -> next;
    curr -> next = prev;
    reverseUtil( curr,next,head );

}

void reverse( struct node **head ) {
    if( !head )
        return;
    reverseUtil( NULL,*head,head );
}

int main() {
    
    struct node *head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(3);
    head1->next->next->next = newNode(4);
    head1->next->next->next->next = newNode(5);
    head1->next->next->next->next->next = newNode(6);
    head1->next->next->next->next->next->next = newNode(7);
    head1->next->next->next->next->next->next->next = newNode(8);
    
    cout << "Link List " << endl;
    printList(head1);

    reverse(&head1);
    cout << "Reverse Link List" << endl;
    printList(head1);

    return 0;

}

