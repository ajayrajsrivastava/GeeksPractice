#include<iostream>
#include<stdlib.h>
using namespace std;


struct node {

    int data;
    struct node *left;
    struct node *right;

};

struct snode{

    //stack implemented as linked list
    struct node  *t;
    struct snode *next;

};

node* newNode( int data ) {

    node *temp    = new node;
    temp -> data  = data;
    temp -> right = NULL;
    temp -> left  = NULL;

    return temp;

}

void push(struct snode **s,struct node* curr) {

    struct snode *snode_new = (struct snode *)malloc(sizeof( struct snode ));


    if( snode_new == NULL )
    {
        cout << "Stack Overflow \n";
        //no memory left
        exit(0);
    }

    snode_new -> t    = curr;
    snode_new -> next = (*s);

    // make new snode_new top of the stack
    (*s) = snode_new;
}


bool isEmpty( struct snode* top) {

    return ( top == NULL )? 1:0;

}

struct node* pop( struct snode** s) {

    struct snode *top;
    struct node  *res;

    if(isEmpty( *s )) { // good to check corner cases

        cout << "Stack Underflow\n";
        exit(0);

    }
    else
    {

        top = *s;
        res = top -> t;
        *s =  top -> next;
        free(top);
        return res;
    }
}


void inOrder( struct node *root ) {

    //intialize stack
    struct snode *s = NULL;
    // curr = root
    struct node  *curr = root;

    bool done = 0;

    while( !done ) {

        if( curr != NULL ) {
            push(&s,curr);
            curr = curr -> left;
        }
        else{

            if(!isEmpty(s))
            {

                curr = pop(&s);
                cout << curr -> data << " ";
                curr =  curr -> right;
            }
            else
                done = 1; //isempty & isnull

        }
    }
}


int main() {

    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);

    inOrder(root);

    return 0;
}

