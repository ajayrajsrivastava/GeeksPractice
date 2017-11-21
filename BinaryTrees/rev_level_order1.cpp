#include<iostream>
using namespace std;

struct  Node{

    int data;
    Node *left  = NULL;
    Node *right = NULL;
    Node( int data ) {
        this -> data = data;
    }
};

void printGivenLevel( Node* root, int level ) {

    if( root == NULL )
        return;

    if( level == 1 )
        cout << root -> data << " ";

    else if ( level > 0 )
    {
        printGivenLevel( root -> left,  level - 1 );
        printGivenLevel( root -> right, level - 1 );
    }


}


int height( Node *root ) {

    if( root == NULL )
        return 0;

    int lh = height( root -> left  );
    int rh = height( root -> right );

    return max( lh,rh ) + 1;
}


void reverseLevelOrder( Node* root ) {

    if( root == NULL )
        return;

    int h = height( root );

//    cout << h << endl;

    for( int i = h; i >= 1; i-- )
        printGivenLevel( root, i );

}


int main() {

    Node *root        = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);

    cout << "Reverse Level Order traversal of binary tree is \n";
    reverseLevelOrder(root);

    return 0;
}
