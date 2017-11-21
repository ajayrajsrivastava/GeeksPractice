#include<iostream>
using namespace std;

struct Node{

    int data;
    Node *left = NULL;
    Node *right = NULL;

    Node( int data ) {

        this -> data = data;

    }

};

void printLeftBoundary( Node *root ) {

    if( root == NULL )
        return;


    if( root -> left != NULL ) {

        cout << root -> data << " ";
        printLeftBoundary( root -> left );

    }

    else if ( root -> right != NULL ) {

        cout << root -> data << " ";
        printLeftBoundary( root -> right );

    }

}


void printRightBoundary( Node *root ) {

    if( root == NULL )
        return;

    if( root -> right != NULL ) {

        printRightBoundary( root -> right );
        cout << root -> data << " ";

    }

    else if( root -> left != NULL ) {

        printRightBoundary( root -> left );
        cout << root -> data << " ";

    }

}


void printLeaves( Node *root ) {

    if ( root == NULL )
        return;

    printLeaves( root -> left );

    if( root -> left == NULL && root -> right == NULL )
        cout << root -> data << " ";

    printLeaves( root -> right );

}


void printBoundary( Node *root ) {

    if( root == NULL )
        return;

    cout << root -> data << " ";

    // 1.print Left Boundary in Top-Down Manner
    printLeftBoundary( root -> left );

    //2.print leaves
    printLeaves( root -> left  );
    printLeaves( root -> right );

    //3.Print Right Boundary in Bottom Up Manner
    printRightBoundary( root -> right );

}

int main() {

    Node *root                = new Node(20);
    root->left                = new Node(8);
    root->left->left          = new Node(4);
    root->left->right         = new Node(12);
    root->left->right->left   = new Node(10);
    root->left->right->right  = new Node(14);
    root->right               = new Node(22);
    root->right->right        = new Node(25);

    printBoundary( root );

    return 0;
}

