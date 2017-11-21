#include<iostream>
#include<queue>
using namespace std;


struct node {

    int data;
    struct node* left;
    struct node* right;

};

node* newNode( int data ) {

    node *temp = new node;
    temp -> data  = data;
    temp -> left  = NULL;
    temp -> right = NULL;

    return temp;
}


int treeHeight( node *root ) {

    if ( root == NULL )     return 0;

    queue<node *>q;
    q.push(root);

    int h = 0;
    while(1) {

        int qsize = q.size();

        if(qsize == 0)
            return h;
        else
            h++;

        while(qsize) {

            node* temp = q.front();
            q.pop();
            if(temp -> left  != NULL )   q.push( temp -> left );
            if(temp -> right != NULL )   q.push( temp -> right );
            qsize--;
        }

    }

}


int main( ) {

    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Height of tree is " << treeHeight(root);
    return 0;

}
