#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

void appendNode( struct node **head,int data) {

    struct node* new_node = new node;
    new_node -> data = data;
    new_node -> next = NULL;
    (*head) -> next = new_node;
    (*head)  = new_node;

}

void reverseList( struct node **start ) {

    struct node *prev = NULL;
    struct node *curr = *start;
    struct node *nex;

    while( curr != NULL ) {
        nex = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nex;
    }
    *start = prev;
}

void printList( struct node *head) {

    struct node*temp = head;
    while( temp!= NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main() {
    //Approach 2 : Change Prev and current
    struct node *head = new node;
    struct node *start = head;
    head -> data = 85;
    head -> next = NULL;

    appendNode(&head,15);
    appendNode(&head,4);
    appendNode(&head,20);

    cout << "Current Linked List" << endl;
    printList(start);

    reverseList(&start);

    cout << "Reversed Linked List" << endl;
    printList(start);

    return 0;
}

