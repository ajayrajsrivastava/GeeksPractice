#include<iostream>
#include<stdlib.h>
using namespace std;

#define Q_SIZE 500

struct node{

    int data;
    struct node* left;
    struct node* right;

};



struct node* newNode( int data ) {

    struct node* node = (struct node*) malloc( sizeof( struct node ) );

    node -> data  = data;
    node -> left  = NULL;
    node -> right = NULL;

    return node;
}

struct node** createQueue( int *front, int *rear ) {

    struct node **queue = (struct node **) malloc( sizeof (struct node*) * Q_SIZE);
    *front = *rear = 0;

    return queue;
}


void push( struct node **queue, int *rear, struct node *node) {

    queue[*rear] = node;
    (*rear) ++;
}

struct node* pop( struct node **queue, int *front) {

    (*front)++;
    return queue[*front - 1];

}

void printLevelOrder( struct node *root ) {

    int rear;
    int front;
    struct node **queue    = createQueue(&front, &rear);
    struct node *temp_node = root;

    while( temp_node ) {

        cout << temp_node -> data << " ";

        if ( temp_node -> left )
            push(queue,&rear,temp_node -> left);

        if ( temp_node -> right )
            push(queue,&rear,temp_node -> right);

        temp_node = pop(queue,&front);
    }

}




int main() {

    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);

    cout << "Level Order traversal of binary tree is" << endl;
    printLevelOrder(root);


    return 0;
}
