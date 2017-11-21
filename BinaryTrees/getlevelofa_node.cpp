#include<iostream>
#include<queue>
#include<stdlib.h>
using namespace std;

struct Node {

    int data;
    Node *left  = NULL;
    Node *right = NULL;

    Node( int data ) {

        this -> data = data;
    }
};


int solve( Node* root, int key, int level ) {

    if( root == NULL )
        return 0;

    if( root -> data == key )
        return level;

    int left = solve( root -> left, key, level + 1 );

    //mutual exclusion since key will be either in left or right subtree
    // if left then return its level else check right subtree

    if( left != 0 ) // if key present then return don't traverse right subtree
        return left;

    int right = solve( root -> right, key, level + 1 );

    return right; // will return either 0 or level of key

}

int getLevel( Node *root, int key ) {

    return solve(root,key,1);


}

//check geeks practice submission { used global var }
int main( ) {


    Node *root        = new Node(3);
    root->left        = new Node(2);
    root->right       = new Node(5);
    root->left->left  = new Node(1);
    root->left->right = new Node(4);

    int maxKey = 5;

    for( int i = 1; i <= maxKey; i++ ) {

        int level = getLevel(root,i);

        if( level != 0 )
            cout << "Key - " << i << " Level - " << level << endl;
    }


    return 0;
}







