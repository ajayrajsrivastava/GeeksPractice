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

int getLevel( Node *root, Node *node, int level ) {

    if( root == NULL )
        return 0;

    if( root == node )
        return level;

    int downLevel = getLevel( root -> left, node, level + 1 );

    if( downLevel != 0 )
        return downLevel;

    return getLevel( root -> right, node, level + 1 );
}

void printGivenLevel( Node *root, Node *node, int level ) {

    if( root == NULL || level < 2 )
        return;

    if( level == 2 ) {

        if( root -> left == node || root -> right == node )
            return;
        //DON'T PRINT NODE & ITS SIBLING

        if( root -> left )
            cout << root -> left -> data << " ";

        if( root -> right )
            cout << root -> right -> data << " ";

    }

    else if ( level > 2 ) {

        printGivenLevel( root -> left, node, level - 1 );
        printGivenLevel( root -> right, node, level - 1 );
    }


}


void printCousins( Node *root, Node *node )
{
    int level = getLevel( root, node, 1 );

    printGivenLevel( root, node, level );

}

int main() {

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(15);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);

    printCousins(root, root->left->right);

    return 0;


}
