#include<iostream>
#include<algorithm>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode ( int data ) {

    struct node *node = (struct node *) malloc( sizeof(struct node) );
    node -> data  = data;
    node -> left  = NULL;
    node -> right = NULL;


    return node;
}

void mirror(struct node* node)
{
    if( node == NULL)  return;


    swap( node -> left , node -> right);
    mirror( node -> left  );
    mirror( node -> right );

}

void inorder( struct node* root) {

    if( root == NULL)   return;

    inorder( root -> left );
    cout << root -> data << " ";
    inorder( root -> right );
}

int main() {

    struct node *root    = newNode(1);
    root->left           = newNode(2);
    root->right          = newNode(3);
    root->left->left     = newNode(4);
    root->left->right    = newNode(5);

    inorder(root); cout << "\n"; // inorder used to verify if correctly mirrored or not
    mirror(root);               // I used preorder for mirroring
    inorder(root); cout << "\n";

    // geeks used postorder traversal
    /*
    void mirror(struct node* node)
{
  if (node==NULL)
    return;
  else
  {
    struct node* temp;

    mirror(node->left);
    mirror(node->right);

    temp        = node->left;
    node->left  = node->right;
    node->right = temp;
  }
}
*/

    return 0;
}
