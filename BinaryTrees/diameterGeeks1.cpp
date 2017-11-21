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

int height( Node *root ) {

    if( root == NULL )
        return 0;

    int lh = height( root -> left  );
    int rh = height( root -> right );

    return max(lh,rh) + 1;

}

int diameter( Node *tree ) {

    if( tree == NULL )
        return 0;

    int lh = height( tree -> left  );
    int rh = height( tree -> right );

    int ld = diameter( tree -> left  );
    int rd = diameter( tree -> right );

    return max( lh+rh+1,max(ld,rd));
}

int  main() {

  Node *root        = new Node(1);
  root->left        = new Node(2);
  root->right       = new Node(3);
  root->left->left  = new Node(4);
  root->left->right = new Node(5);

  cout << "Diameter of the given binary tree is " << diameter(root) << endl;

  return 0;

}
