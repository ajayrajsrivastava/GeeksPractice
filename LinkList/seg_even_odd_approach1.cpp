#include <iostream>
#include <cstdlib>
using namespace std;

#define DBG cout << "DEBUG" << endl

struct node{
    int data;
    struct node* next;
};


void createLinkList(struct node* head,int n) {

        int data;
        while(n--){
            cin >> data;
            struct node* NODE = (struct node*)malloc(sizeof(struct node*));
            NODE -> data = data;
            head -> next = NODE;
            head = NODE;
        }
        head -> next = NULL;
}

void printLinkList(struct node* head) {

    head = head -> next;
    while( head != NULL ) {
        cout << head -> data <<" ";
        head = head -> next;
    }
    cout << endl;
}

void createSubLinkList(struct node* head,int data) {

    struct node* NODE = (struct node*)malloc(sizeof(struct node));
    NODE -> data = data;
    head -> next = NODE;

}

void createEvenandOddLinkList(struct node* head,struct node* evenHead,struct node* oddHead) {

    head = head -> next;
    while(head!=NULL) {

        if((head -> data)%2)   {
            createSubLinkList(evenHead,head -> data);
            evenHead = evenHead -> next;
        }
        else {
            createSubLinkList(oddHead,head -> data);
            oddHead = oddHead -> next;
        }
    head = head -> next;

    }

}

void AttachEvenOddLinkList(struct node* evenHead,struct node* oddHead) {

    if(evenHead -> next != NULL)   //Corner Cases
        evenHead =  evenHead -> next;
    else if(oddHead -> next != NULL)
        oddHead  =  oddHead  -> next;

    while(oddHead->next!=NULL){
        oddHead = oddHead->next;

    }

    oddHead->next = evenHead;

}


        /*
        Approach 1
        Traverse original link list and move all odd nodes to a separate link list of odd nodes.
        Now original list will consist of even nodes only.Attach even node link list -> to odd node link list
        */


int main() {

    int t,n;
    cin >> t;
    while( t-- ) {

        cin >> n ;

        struct node* head = (struct node*)malloc(sizeof(struct node));
        createLinkList(head,n);


        struct node* evenHead = (struct node*)malloc(sizeof(struct node));
        struct node* oddHead  = (struct node*)malloc(sizeof(struct node));
        createEvenandOddLinkList(head,evenHead,oddHead);


        AttachEvenOddLinkList(evenHead,oddHead); //attaching odd list at end of even list

        printLinkList(oddHead);


        //Refresh or Clear
        head -> next = NULL;
        oddHead -> next = NULL;
        evenHead -> next = NULL;
        //Accepted
    }

    return 0;
}
