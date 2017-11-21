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

void convertTree( Node *root ) {

    if( root == NULL || (root -> left == NULL && root -> right == NULL) )
        return;

    convertTree( root -> left  );
    convertTree( root -> right );


    int sum = 0;

    if( root -> left != NULL )
        sum += root -> left -> data;

    if( root -> right != NULL )
        sum += root -> right -> data;

    int diff = sum - ( root -> data );

    if( diff == 0)
        return;

    else if( diff > 0 )
        root -> data = root -> data + diff;

    else {

        diff = -diff;
        if( root -> left != NULL )
        {
            root -> left -> data += diff;
            convertTree( root -> left );
        }

        else
        {

            root -> right -> data += diff;
            convertTree( root -> right );
        }

    }

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
