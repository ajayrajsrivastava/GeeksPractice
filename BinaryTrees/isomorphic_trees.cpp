#include<iostream>
using namespace std;

struct Node{

    int data;
    Node *left  = NULL;
    Node *right = NULL;

    Node( int data )
    {
        this -> data = data;
    }


};

bool isIsomorphic( Node* n1, Node* n2 ) {


    if( n1 == NULL && n2 == NULL )
        return true;

    if( n1 == NULL || n2 == NULL )
        return false;

    if( n1 -> data != n2 -> data )
        return false;

    //NOT FLIPPED
    bool c1 = isIsomorphic( n1 -> left,  n2 -> left  );
    bool c2 = isIsomorphic( n1 -> right, n2 -> right );

    //FLIPPED
    bool c3 = isIsomorphic( n1 -> left,  n2 -> right );
    bool c4 = isIsomorphic( n1 -> right, n2 -> left  );

    return ( (c1 && c2) || (c3 && c4) );

}

int main(){

    Node *n1        = new Node(1);
    n1->left        = new Node(2);
    n1->right       = new Node(3);
    n1->left->left  = new Node(4);
    n1->left->right = new Node(5);
    n1->right->left  = new Node(6);
    n1->left->right->left = new Node(7);
    n1->left->right->right = new Node(8);

    Node *n2         = new Node(1);
    n2->left         = new Node(3);
    n2->right        = new Node(2);
    n2->right->left   = new Node(4);
    n2->right->right   = new Node(5);
    n2->left->right    = new Node(6);
    n2->right->right->left = new Node(8);
    n2->right->right->right = new Node(7);

    if (isIsomorphic(n1, n2) == true)
       cout << "Yes";
    else
      cout << "No";

    return 0;
}
