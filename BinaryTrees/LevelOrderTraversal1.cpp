#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{

    int data;
    struct node* left;
    struct node* right;

};

struct node* newNode( int data ) {

    struct node* node = (struct node*) malloc( sizeof(struct node) ) ;
    node -> data  = data;
    node -> left  = NULL;
    node -> right = NULL;

    return node;
}

int height( struct node* node) {

    if( node == NULL )  return 0;

    int lh = height( node -> left  );
    int rh = height( node -> right );


    //cout << node -> data << endl;
    return max(lh,rh) + 1 ;
}


void printGivenLevel( struct node* node, int level ) {

    if( node == NULL )  return;

    if( level == 1 )    cout << node -> data << " ";

    else if( level > 1 ) {

        printGivenLevel( node -> left ,  level - 1 );
        printGivenLevel( node -> right , level - 1 );
    }

}


void printLevelOrder( struct node* root) {

    int h = height(root);
    cout << h << endl;
    for(int i = 1; i <= h; i++) {
        printGivenLevel(root,i);
    }

}





int main() {


    struct node* root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);

    cout << "Level Order traversal of binary tree is \n";
    printLevelOrder(root);

    return 0;

}
