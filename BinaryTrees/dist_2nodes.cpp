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



Node *solve( Node *root, int n1, int n2, int &d1, int &d2, int &dist, int level ) {

    if( root == NULL )
        return NULL;

    if( root -> data == n1 ) {

        d1 = level;
        return root;
    }

    if( root -> data == n2 ) {

        d2 = level;
        return root;

    }

    Node *left  = solve( root -> left,  n1, n2, d1, d2, dist , level + 1 );
    Node *right = solve( root -> right, n1, n2, d1, d2, dist,  level + 1 );

    if( left && right ){
        dist = d1 + d2  - 2 * level;
        return root;
    }

    return ( left != NULL ) ? left : right;

}

int findLevel( Node *root, int key, int level ) {

    if( root == NULL )
        return -1;

    if( root -> data == key )
        return level;

    int l = findLevel( root -> left, key, level + 1 );

    return ( l != -1 ) ? l : findLevel( root -> right, key, level + 1 );
}


int findDistance( Node *root, int n1, int n2 ) {

    //DISTANCE
    int d1 = -1;
    int d2 = -1;
    int dist;

    Node *LCA = solve( root, n1, n2, d1, d2, dist, 1 ); // IF TAKE 0 THEN DIST RETURN CAN BE < 0

    if( d1 != -1 && d2 != -1 )
        return dist;

    // IF ANCESTOR ( SINCE ONLY LCA IS RETURNED )
    // RETURN LEVEL OF NODE WHEN TREE ROOTED AT LCA
    if( d1 != -1 ) {

        return  findLevel( LCA, n2, 0 );

    }

    if( d2 != -1 ) {

        return  findLevel( LCA, n1, 0 );
    }

    return -1;

}

int main() {

    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    cout << "Dist(4, 5) = " << findDistance(root, 4, 5);
    cout << "\nDist(4, 6) = " << findDistance(root, 4, 6);
    cout << "\nDist(3, 4) = " << findDistance(root, 3, 4);
    cout << "\nDist(2, 4) = " << findDistance(root, 2, 4);
    cout << "\nDist(8, 5) = " << findDistance(root, 8, 5);
    return 0;

}

