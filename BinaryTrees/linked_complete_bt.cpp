#include<iostream>
#include<queue>

using namespace std;

struct Node{

    int data;
    Node *left = NULL;
    Node *right = NULL;
    Node( int data ) {

        this -> data = data;
    }
};

bool hasBothChild( Node *root ) {

    return ( root != NULL && root -> left != NULL && root -> right != NULL );

}


void levelOrder( Node *root ) {


    queue< Node *> q;

    q.push(root);

    while( ! q.empty() ) {


        Node *temp = q.front();
        q.pop();

        cout << temp -> data << " ";

        if( temp -> left != NULL )
            q.push( temp -> left );

        if( temp -> right != NULL )
            q.push( temp -> right );

    }

}


void insert( Node **root, int data, queue< Node * > &q ) {

    Node *temp = new Node(data);

    if( *root == NULL )
        *root = temp;

    else {


        Node *front = q.front();


        if( front -> left == NULL )
            front -> left = temp;

        else if( front -> right == NULL )
            front -> right = temp;

        if( hasBothChild(front) )
            q.pop();

    }

    q.push(temp);

}

int main() {

    Node *root = NULL;
    queue< Node * > q;

    for( int i = 1; i <= 12; i++ ) {

        insert(&root, i, q);
    }


    levelOrder(root);
    return 0;
}
