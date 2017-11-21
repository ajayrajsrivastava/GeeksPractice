#include<iostream>
using namespace std;

struct Node{

    int data;
    Node *left  = NULL;
    Node *right = NULL;

    Node( int data ) {

        this -> data = data;
    }
};

int height( Node *root ) {

    if( root == NULL )  return 0;

    int lh = height( root -> left  );
    int rh = height( root -> right );

    return max(lh,rh) + 1;
}

void printGivenLevel( Node *root,int level,bool ltr ) {

    if( root == NULL )  return;

    if ( level == 1 )
        cout << root -> data << " ";

    else if( level > 1 ) {

        if(ltr) {

            printGivenLevel( root -> left,  level-1, ltr);
            printGivenLevel( root -> right, level-1, ltr);

        }
        else {

            printGivenLevel( root -> right, level-1, ltr);
            printGivenLevel( root -> left,  level-1, ltr);

        }
    }
}



void printSpiral( Node *root ) {

    if( root == NULL )  return;

    bool ltr = 0;
    for( int i = 1; i <= height(root); i++ ) {

        printGivenLevel( root,i,ltr );
        ltr = !ltr;

    }
}

int main() {

    Node *root         = new Node(1);
    root->left         = new Node(2);
    root->right        = new Node(3);
    root->left->left   = new Node(7);
    root->left->right  = new Node(6);
    root->right->left  = new Node(5);
    root->right->right = new Node(4);

    cout << "Spiral Order traversal of binary tree is \n";
    printSpiral(root);

    return 0;

}
