#include <iostream>
#include <cstdlib>
using namespace std;

#define DBG cout << "DEBUG" << endl

struct node{
    int data;
    struct node* next;
};

struct node* start;

struct node* createLinkList(struct node* head,int n) {

        int data;
        while(n--){
            cin >> data;
            struct node* NODE = (struct node*)malloc(sizeof(struct node*));
            NODE -> data = data;
            head -> next = NODE;
            head = NODE;
        }
        head -> next = NULL;
        return head;
}

void printLinkList(struct node* head) {

    head = head -> next;
    while( head != NULL ) {
        cout << head -> data <<" ";
        head = head -> next;
    }
    cout << endl;
}

void modifyLinkList(struct node* head,struct node* lastnode) {

    struct node* ptr1 = head;
    struct node* ptr2 = head -> next;


    // to get prev node in case of single LL keep 2 consecutive pointers
    // in case of doubly LL only 1 ptr req to traverse

    while(ptr2 != NULL) {

        if((ptr2 -> data)%2 != 0){
            // remove odd node
            struct node* curr = ptr2;
            ptr2 = ptr2 -> next;
            ptr1 -> next = ptr2;

            curr -> next = NULL;
            lastnode -> next = curr;
            if(lastnode -> next != NULL)
                lastnode = lastnode -> next;

        }

            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        // fucking infinite loop...

        printLinkList(start);

    }

}
        /*
        Approach 2
        Traverse original link list and keep a pointer at last node of the original LL.As you
        traverse link list and encounter odd nodes remove that odd node from its pos
        and place it at the end and so on...
        Now modified list will consist of even nodes  -> to odd node
        */


int main() {

    int t,n;
    cin >> t;
    while( t-- ) {

        cin >> n ;

        struct node* head = (struct node*)malloc(sizeof(struct node));
        struct node* lastnode = createLinkList(head,n);
        start = head;

        modifyLinkList(head,lastnode);


        printLinkList(head);
        //Refresh or Clear
        head -> next = NULL;

        //Accepted
    }

    return 0;
}
