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


void reverse(struct node **head ) {

    if(*head == NULL)
        return;

    struct node *first = (*head);
    struct node *rest = first -> next;

    if(rest == NULL )
        return;       // single node

    reverse(&rest);
    first -> next -> next = first;

    //finally..
    first -> next = NULL;
    (*head) = rest;
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


