#include<iostream>
#include<stack>
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

    stack<Node *>s1; // R-->L
    stack<Node *>s2; // L-->R

    s1.push( root );

    while( !s1.empty() || !s2.empty() ) {


        while( !s1.empty() ) {

            Node *top = s1.top();
            cout << top -> data << " ";
            s1.pop();

            if( top -> right != NULL )
                s2.push( top -> right );

            if( top -> left != NULL )
                s2.push( top -> left );


        }

        while( !s2.empty() ) {

            Node *top = s2.top();
            cout << top -> data << " ";
            s2.pop();

            if( top -> left != NULL )
                s1.push( top -> left );

            if( top -> right != NULL )
                s1.push( top -> right );


        }

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
