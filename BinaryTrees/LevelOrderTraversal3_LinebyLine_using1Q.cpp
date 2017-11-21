#include<iostream>
#include<queue>
using namespace std;

struct node{

    int data;
    struct node *left;
    struct node *right;

};


node* newNode( int data ) {

    node    *temp = new node;
    temp -> data  = data;
    temp -> left  = NULL;
    temp -> right = NULL;
    return temp;
}

void printLevelOrder( node *root ) {


    if ( root == NULL )     return;

    queue<node *>q;
    q.push(root);

   // cout << "DEBUG" << endl;

    while( !q.empty() ) {


        int qsize = q.size();


        while( qsize-- ) {


            node *temp = q.front();
            q.pop();
            cout << temp -> data << " ";
            if( temp -> left != NULL ) q.push( temp -> left );
            if( temp -> right != NULL ) q.push( temp -> right );

        }

        cout << endl;
    }


}

int main()
{
    // Let us create binary tree shown in above diagram
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    printLevelOrder(root);
    return 0;
}
