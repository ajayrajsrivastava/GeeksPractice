#include<iostream>
#include<queue>
using namespace std;

struct node{

    int data;
    struct node *left;
    struct node *right;
};

void levelOrder( node *root ) {

    if( root == NULL )  return;

    queue<node *> q1,q2;
    q1.push( root );

    while( !q1.empty() || !q2.empty() ) {


        while( !q1.empty() ) {

            node *temp = q1.front(); q1.pop();
            cout << temp -> data << " ";
            if(temp -> left !=NULL ) q2.push(temp -> left );
            if(temp -> right !=NULL ) q2.push(temp -> right);

        }

        cout << endl;

        while( !q2.empty() ) {

            node *temp = q2.front(); q2.pop();
            cout << temp -> data << " ";
            if(temp -> left !=NULL ) q1.push(temp -> left );
            if(temp -> right !=NULL ) q1.push(temp -> right);

        }

        cout << endl;
    }

}

node* newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Driver program to test above functions
int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    levelOrder(root);
    return 0;
}
