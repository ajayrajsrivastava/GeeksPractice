#include<iostream>
#include<queue>
#include<stack>

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

void printQ( queue<node*> q) {

    while(!q.empty()) {

        cout << q.front() -> data << " ";
        q.pop();

    }


}



void printRevQ( queue<node*> q) {

    stack<node*> s;

    while(!q.empty()) {

        s.push(q.front());
        q.pop();
    }

    while(!s.empty()) {

       cout << s.top() -> data << " ";
       s.pop();
    }

}

void printLevelOrder( node *root ) {


    if ( root == NULL )     return;

    queue<node *>q;
    q.push(root);

   // cout << "DEBUG" << endl;
    int i = 0;
    while(1) {


        int qsize = q.size();
        if (qsize == 0 )    return;

        if(i%2)
            printQ(q);

        else
            printRevQ(q);


        while( qsize ) {


            node *temp = q.front();
            q.pop();
            if( temp -> left != NULL ) q.push( temp -> left );
            if( temp -> right != NULL ) q.push( temp -> right );
            qsize--;

        }

        cout << endl;i++;
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

