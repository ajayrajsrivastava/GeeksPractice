#include<iostream>
#include<stdlib.h>
using namespace std;


struct node {

    int data;
    struct node *left;
    struct node *right;

};

struct node *newNode( int data ) {

    struct node *node = (struct node *) malloc( sizeof (struct node ) );
    node -> data  = data;
    node -> left  = NULL;
    node -> right = NULL;

    return node;
}

void printArray(int path[],int pathlen) {

    for(int i = 0; i < pathlen; i++ ) {
        cout << path[i] << " " ;
    }

    cout << "\n";
}

void printPathsRecur( struct node *root,int path[],int pathlen ) {


    if( root == NULL )  return;

    path[pathlen] = root -> data;
    pathlen++;

    if( root -> left == NULL && root -> right == NULL ) {

        printArray(path,pathlen);

    }
    else
    {
        printPathsRecur(root->left,path,pathlen);
        printPathsRecur(root->right,path,pathlen);

    }
}

void printPaths( struct node *root) {

    int path[1000];
    printPathsRecur(root,path,0);
                    // tree,patharray,pathlen
}




int main( ) {

    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);

    printPaths(root);


    return 0;
}
