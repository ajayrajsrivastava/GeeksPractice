#include<iostream>
#include<queue>
#include<stdlib.h>
using namespace std;

struct node{

    int data;
    struct node *left;
    struct node *right;

};


struct node *newNode ( int data ) {

    struct node *node = (struct node*)malloc( sizeof( struct node ) );
    node -> data  = data;
    node -> left  = NULL;
    node -> right = NULL;

    return node;

}


bool areIdentical( struct node *root1,struct node *root2) {

    if( !root1 && !root2 )     return true;
    //if both empty

    if( !root1 || !root2 )    return false;
    // if one of them is empty


    queue< struct node* >q1,q2;
    q1.push( root1 );
    q2.push( root2 );



    while( !q1.empty() && !q2.empty() ) {

       // cout << root1 -> data << " " << root2 -> data << endl;

        struct node *x = q1.front();
        struct node *y = q2.front();

        //cout << q1.front() -> data <<  endl;
        //cout << q2.front() -> data <<  endl;


        if( x -> data != y-> data )     return false;

        q1.pop();q2.pop();

        if( x -> left  && y -> left  )
        {
            q1.push( x -> left );
            q2.push( y -> left );

        }

        else if ( x -> left  || y -> left  ) // 1 || 0 , 0 || 1
            return false;





        if( x -> right && y -> right  )
        {
            q1.push( x -> right );
            q2.push( y -> right );

        }

         else if ( x -> right || y -> right ) // 1 || 0 , 0 || 1
            return false;


    }
        return true;

}

int main() {

    struct node *root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);

    struct node *root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);

    areIdentical(root1, root2)? cout << "Yes": cout << "No";

    return 0;

}
