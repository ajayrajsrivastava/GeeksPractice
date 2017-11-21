#include<iostream>
#include<cstdlib>
using namespace std;

struct Node {

    int data;
    Node *left  = NULL;
    Node *right = NULL;

    Node( int data ) {

        this -> data = data;
    }

};



void inorder( Node *root ) {

    if( root == NULL )
        return ;

     inorder( root -> left ) ;
     cout  << root -> data << " ";
     inorder( root -> right );

}

void solve( Node *root, int depth, int *maxDepth, bool isLeft, Node **res ) {

    if( root == NULL )
        return;

    if( isLeft && root -> left == NULL && root -> right == NULL && depth > *maxDepth ) {

        *maxDepth = depth;
        *res = root;
        return;
    }

    solve( root -> left,  depth + 1, maxDepth, true,  res  );
    solve( root -> right, depth + 1, maxDepth, false, res  );


}

Node* deepestLeftLeaf( Node *root ) {

   int maxDepth = 0;
   Node *res = NULL;

   solve(root,0,&maxDepth,false,&res);
   return res;
}


int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->right = new Node(7);
    root->right->right->right = new Node(8);
    root->right->left->right->left = new Node(9);
    root->right->right->right->right = new Node(10);

    Node *result = deepestLeftLeaf(root);

    if (result)
        cout << "The deepest left child is " << result -> data;
    else
        cout << "No left leaf in given tree";

    return 0;
}



