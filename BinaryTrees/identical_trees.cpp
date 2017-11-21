#include<iostream>
#include<stdlib.h>

using namespace std;

struct node {

    int data;
    struct node *left;
    struct node *right;

};


bool check;
void inorder( Node *r1,Node  *r2) {


    if( r1 == NULL && r2 == NULL)
        return;

    if( r1 == NULL)
    {
        check = false;
        return;
    }

    if( r2 == NULL)
    {
        check = false;
        return;
    }

    inorder(r1->left,r2->left);

    if( r1 -> data != r2 -> data)
        check = false;


    inorder(r1->right,r2->right);
}

bool isIdentical(Node *r1, Node *r2)
{

    check = true;
    inorder(r1,r2);


    return check;


}
struct node* newNode( int data ) {

    struct node* node = (struct node*)malloc(sizeof(struct node));
    node -> data  = data;
    node -> left  = NULL;
    node -> right = NULL;

    return node;
}

int main( ){

    struct node *root1 = newNode(1);
    root1->left        = newNode(2);
    root1->right       = newNode(3);
    root1->left->left  = newNode(4);
    root1->left->right = newNode(5);

    struct node *root2 = newNode(1);
    root2->left        = newNode(2);
    root2->right       = newNode(3);
    root2->left->left  = newNode(4);
    root2->left->right = newNode(5);

    cout << isIdentical(root1, root2) << endl;



    return 0;
}

