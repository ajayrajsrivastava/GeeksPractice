#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct  Node{

    int data;
    Node *left  = NULL;
    Node *right = NULL;
    Node( int data ) {
        this -> data = data;
    }
};



int getLevelDiff( Node* root ) {

    if( root == NULL )
        return 0;


    queue <Node *> Q;

    Q.push( root );
    int level = 1; // Level of root node

    int oddSum  = 0;
    int evenSum = 0;

    while( !Q.empty() ) {

        int nodeCount = Q.size();

        while( nodeCount -- ) {



            Node *root = Q.front();
            Q.pop();

            if( level & 1 )
                oddSum  += root -> data;
            else
                evenSum += root -> data;



            if( root -> right != NULL )
                Q.push( root -> right );

            if( root -> left != NULL )
                Q.push( root -> left );


        }

        level += 1;

    }

    return (oddSum - evenSum);
}


int main() {

    Node *root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left  = new Node(1);
    root->left->right = new Node(4);
    root->left->right->left = new Node(3);
    root->right->right = new Node(8);
    root->right->right->right = new Node(9);
    root->right->right->left = new Node(7);

    cout << "Diff : ";

    cout << getLevelDiff(root);

    return 0;
}

