#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

void push( struct node **head,int data) {

    struct node* temp = new struct node;
    temp -> data = data;
    temp -> next = (*head);
    (*head) = temp;

}

void printList( struct node *head) {

    struct node*temp = head;
    while( temp!= NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

int main() {
    //Approach 1 : Push upcoming nodes as head
    struct node *head = NULL;
    push(&head,85);
    push(&head,15);
    push(&head,4);
    push(&head,20);

    cout << "Reversed Linked List" << endl;
    printList(head);

    return 0;
}
