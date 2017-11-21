#include<iostream>
using namespace std;

struct Node {

    int data;
    Node *left = NULL;
    Node *right = NULL;

    Node( int data ) {

        this -> data = data;
    }

};

void printInorder( Node *root ) {

    if( root == NULL )
        return;

    printInorder( root -> left );
    cout << root -> data << " ";
    printInorder( root -> right );


}

Node* buildTree( int pre[], char preLN[], int n, int *index_ref ) {

    int index = (*index_ref);

    // all nodes constructed
    if( index == n )
        return NULL;

    Node *root = new Node( pre[(index)] );
    (*index_ref)++;

    if( preLN[index] == 'N') {

        root -> left  = buildTree( pre, preLN, n, index_ref );
        root -> right = buildTree( pre, preLN, n, index_ref );

    }

    return root;
}

Node* solve( int pre[], char preLN[], int n ) {

    int index = 0;
    return buildTree( pre, preLN, n, &index );

}

int main() {



    int  pre[]   = {10, 30, 20, 5, 15};
    char preLN[] = {'N', 'N', 'L', 'L', 'L'};

    int n = sizeof(pre)/sizeof(pre[0]);

    Node *root = solve(pre, preLN, n);


    printInorder( root );

    return 0;
}
