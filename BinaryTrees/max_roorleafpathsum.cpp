#include<iostream>
#include<climits>
using namespace std;


struct Node {

    int data;
    Node *left  = NULL;
    Node *right = NULL;

    Node( int data ) {

        this -> data = data;

    }
};

bool isLeaf( Node *root ) {

    if( root -> left == NULL && root -> right == NULL )
        return true;

    return false;

}


void getTargetLeaf( Node *root, int *max_sum_ref, int curr_sum, Node **target_leaf_ref ) {

    if( root == NULL )
        return;

    curr_sum = curr_sum + root -> data;

    if( isLeaf( root ) ) {

        if( curr_sum > (*max_sum_ref) )  {

            *max_sum_ref     = curr_sum;
            *target_leaf_ref = root;
        }

    }

    getTargetLeaf( root -> left,  max_sum_ref, curr_sum, target_leaf_ref );
    getTargetLeaf( root -> right, max_sum_ref, curr_sum, target_leaf_ref );

}


bool printPath( Node *root, Node **target_leaf ) {

    if( root == NULL )
        return false;

    if( root == ( *target_leaf ) || printPath( root -> left, target_leaf ) || printPath( root -> right, target_leaf ) )
    {
        cout << root -> data << " ";
        return true;
    }

    return false;
}

int maxSumPath( Node *root ) {


    if( root == NULL )
        return 0;

    Node *target_leaf;
    int max_sum = INT_MIN;

    getTargetLeaf( root, &max_sum, 0, &target_leaf );

    printPath( root, &target_leaf );

    return max_sum;


}

int main() {

    Node *root        = new Node(10);
    root->left        = new Node(-2);
    root->right       = new Node(7);
    root->left->left  = new Node(8);
    root->left->right = new Node(-4);


    cout << "Path : " << endl;

    int sum = maxSumPath(root);

    cout << endl << "Sum : " << sum << endl;

    return 0;
}

