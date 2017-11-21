#include<iostream>
#include<stdlib.h>

using namespace std;

struct node {

    int data;
    struct node *left;
    struct node *right;

};


void MorrisTraversal( struct node *root ) {

    if( root == NULL ) return;

    struct node *curr = root;
    struct node *pre ;

    while( curr != NULL ) {


        if( curr -> left == NULL ) //if not exists left of  curr
        {
            cout << curr -> data << " ";
            curr = curr -> right;
        }
        else {

            // if left of curr exits
            // find inorder predecessor of current node
            pre = curr -> left;

            while( pre -> right != NULL && pre -> right != curr )
                pre = pre -> right;

            if( pre -> right == NULL )
            {
                pre -> right = curr;
                curr = curr -> left;
            }
            else
            {

                pre -> right = NULL;
                cout << curr -> data << " ";
                curr =  curr -> right;
            }


        }

    }

}

struct node* newNode( int data ) {

    struct node* node = (struct node*)malloc(sizeof(struct node));
    node -> data  = data;
    node -> left  = NULL;
    node -> right = NULL;

    return node;
}

int main( ){

    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);


    MorrisTraversal(root);



    return 0;
}
