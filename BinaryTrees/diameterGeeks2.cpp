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


// return diameter and height
int diameter2( Node *tree,int* height ) {

    if( tree == NULL )
    {
        *height = 0;
        return 0;
    }

    int lh = 0; int rh = 0;

    int ld = diameter2( tree -> left,  &lh );
    int rd = diameter2( tree -> right, &rh );

    *height = max(lh,rh) + 1;

    return max( lh+rh+1,max(ld,rd));
}


int  main() {

  Node *root        = new Node(1);
  root->left        = new Node(2);
  root->right       = new Node(3);
  root->left->left  = new Node(4);
  root->left->right = new Node(5);

  int height = 0;
  cout << "Diameter of the given binary tree is " << diameter2( root, &height ) << endl;

  return 0;

}
