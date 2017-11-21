#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

struct Node{

    int data;
    Node *left  = NULL;
    Node *right = NULL;
    Node( int data ) {
        this -> data = data;
    }
};

Node* solve( Node *root, int n1, int n2, bool &v1, bool &v2 )
{

    if( root == NULL )
        return NULL;

    if( root -> data == n1 ) {
        v1 = true;
        return root;
    }

    if( root -> data == n2 ) {
        v2 = true;
        return root;
    }

    Node *left  = solve( root -> left,  n1, n2, v1, v2 );
    Node *right = solve( root -> right, n1, n2, v1, v2 );

    if( left && right )
        return root;

    return ( left != NULL ) ? left : right;

}


Node* findLCA( Node *root, int n1, int n2 ) {

    //NOT VISITED
    bool v1 = false;
    bool v2 = false;

    Node *LCA = solve( root, n1, n2, v1, v2 );

    if( v1 && v2 )
        return LCA;

    return NULL;
}

int main() {

    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Node *lca =  findLCA(root, 4, 5);

    if (lca != NULL)
       cout << "LCA(4, 5) = " << lca -> data;
    else
       cout << "Keys are not present ";

    lca =  findLCA(root, 4, 10);

    if (lca != NULL)
       cout << "\nLCA(4, 10) = " << lca -> data;
    else
       cout << "\nKeys are not present ";

    return 0;
}
