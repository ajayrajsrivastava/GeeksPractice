#include <iostream>
#include <string.h>
using namespace std;

const int SIZE = 256;

struct node {
    char data;
    struct node *prev;
    struct node *next;
};

void appendNode( struct node **head,struct node **tail,char inp) {

    struct node *temp = new node;
    temp -> data = inp;
    temp -> prev = temp -> next = NULL;

    if( *head == NULL) {
        *head = *tail = temp;
        return ;
    }
    temp -> prev = *tail;
    (*tail) -> next = temp;
    *tail = temp;
}

void removeNode(struct node **head,struct node **tail,struct node *temp) {

    if( *head == NULL ) {
        return;
    }

    if( *head == temp ) {
        *head = (*head) -> next;
    }

    if( *tail == temp ) {
        *tail = (*tail) -> prev;
    }
    if( temp -> next != NULL ) {
        temp -> next -> prev = temp -> prev;

    }
    if( temp -> prev !=NULL ) {
        temp -> prev -> next = temp -> next;
    }
    delete(temp);
}

void firstNonRep ( string stream ) {

    bool rep[SIZE];
    memset(rep,false,sizeof(rep));

    struct node *inDLL[SIZE];
    //memset(inDLL,NULL,sizeof(inDLL)); produces warning
    for( int i = 0 ;i < SIZE ; i++ ) {
        inDLL[i] = NULL;
    }

    struct node *head = NULL;
    struct node *tail = NULL;

    for(int i = 0; i < stream.size(); i++ ) {
        char inp = stream[i];

       // cout << inp << " " << rep[inp] << endl;

        if(!rep[inp]) {
            if( inDLL[inp] == NULL ) {
                appendNode(&head,&tail,inp);
                inDLL[inp] = tail;

            }
            else {
                removeNode(&head,&tail,inDLL[inp]);
                inDLL[inp] = NULL;
                rep[inp] = true;

            }
        }
        if(head != NULL)
            cout << head->data << " ";
        else
            cout << "-1" << " ";

    }
    cout << endl;
}


int main() {

    int t,n;
    string stream;
    cin >> t;
    while ( t-- ) {
        cin >> n;
        while( n-- ) {

            char inp;
            cin >> inp;
            if(inp != ' ') {
                stream.push_back(inp);
            }
        }
       // cout << stream << endl;
        firstNonRep(stream);
        stream.clear();
    }
    return 0;
}
