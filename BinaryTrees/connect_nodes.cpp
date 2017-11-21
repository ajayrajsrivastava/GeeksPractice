#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;

struct Node{

    int data;
    Node *left      = NULL;
    Node *right     = NULL;
    Node *nextRight = NULL;
    Node( int data ) {
        this -> data = data;
    }
};


void inorder( Node *root ) {

    if( root == NULL )
        return ;

    inorder( root -> left );
    cout << root -> data << " ";
    inorder( root -> right );
}


void levelorder(Node *root)
{
    while(root != NULL ) {

        Node * temp = root;
        while( temp != NULL ) {

            cout << temp -> data << " ";
            temp = temp -> nextRight;
        }

        root = root -> left;
    }
}


void solve( Node *root ) {

    if( root == NULL )
        return;

    queue<Node *>q;
    q.push(root);

    int qsize;

    while(!q.empty()) {

        qsize = q.size();

        while(qsize--) {

            Node *temp = q.front();q.pop();

            if( qsize == 0 )
                temp -> nextRight = NULL;
            else
                temp -> nextRight = q.front();

            if( temp -> left != NULL )
                q.push( temp -> left );

            if( temp -> right != NULL )
                q.push( temp -> right );

        }


    }

}




int main() {

    Node *root        = new Node(10);
    root->left        = new Node(20);
    root->right       = new Node(30);
    root->left->left  = new Node(40);
    root->left->right = new Node(60);


    solve(root);

    levelorder(root); //See implementation
    cout << endl;
    inorder(root);

    return 0;

}


