#include<iostream>
using namespace std;


struct Node {

    int data;
    Node *left  = NULL;
    Node *right = NULL;

    Node( int data ) {

        this -> data = data;
    }
};


void printInorder( Node *root ) {

    if( root == NULL )      return;

    printInorder( root -> left );
    cout << root -> data << " ";
    printInorder( root -> right );

}

void increment( Node *root,int diff ) {


    if( root -> left != NULL ) {

        root -> left -> data += diff;
        increment( root -> left, diff );
    }
    else if ( root -> right != NULL ) {

        root -> right -> data += diff;
        increment( root -> right, diff );
    }


}


void convertTree( Node *root ) {

    int left = 0; int right = 0;int diff = 0;


    if( root == NULL || (root -> left == NULL && root -> right == NULL) )
        return;

    convertTree( root -> left  );
    convertTree( root -> right );


    if( root -> left != NULL )
        left = root -> left -> data;

    if( root -> right != NULL )
        right = root -> right -> data;


    diff = ( left + right ) - root -> data;

    if( diff > 0)
        root -> data = root -> data + diff;

    if( diff < 0 )
        increment( root,-diff ); // inc root -> child by diff
        // -diff to make diff postive

}


int main( ){



  Node *root         = new Node(50);
  root->left         = new Node(7);
  root->right        = new Node(2);
  root->left->left   = new Node(3);
  root->left->right  = new Node(5);
  root->right->left  = new Node(1);
  root->right->right = new Node(30);

  cout << "Inorder traversal before conversion\n " ;
  printInorder(root);

  convertTree(root);

  cout << "\nInorder traversal after conversion\n ";
  printInorder(root);

  return 0;

}
