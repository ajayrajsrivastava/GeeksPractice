#include<iostream>
#include<cstdlib>
#include<queue>

using namespace std;

struct Node {

    int data;
    Node *left  = NULL;
    Node *right = NULL;

    Node( int data ) {

        this -> data = data;
    }

};



void inorder( Node *root ) {

    if( root == NULL )
        return ;

     inorder( root -> left ) ;
     cout  << root -> data << " ";
     inorder( root -> right );

}

void solve( Node *root, int depth, int *maxDepth, bool isLeft, Node **res ) {

    if( root == NULL )
        return;

    if( isLeft && root -> left == NULL && root -> right == NULL && depth > *maxDepth ) {

        *maxDepth = depth;
        *res = root;
        return;
    }

    solve( root -> left,  depth + 1, maxDepth, true,  res  );
    solve( root -> right, depth + 1, maxDepth, false, res  );


}

Node* deepestLeftLeaf( Node *root ) {

   int maxDepth = 0;
   Node *res = NULL;

   solve(root,0,&maxDepth,false,&res);
   return res;
}


Node* nextRight( Node *root, int key ) {

    if( root == NULL )
        return 0;

    queue< Node * > q;
    queue<   int  > l;

    int level = 0;
    q.push( root  );
    l.push( level );

    while( !q.empty() ) {


        Node *temp = q.front(); q.pop();
        level = l.front(); l.pop();

        if( temp -> data == key ) {

            if( l.empty() || l.front() != level )
                return NULL;

            return q.front();
        }

        if( temp -> left != NULL )
        {

            q.push( temp -> left );
            l.push( level + 1 );
        }

        if( temp -> right != NULL )
        {

            q.push( temp -> right );
            l.push( level + 1 );
        }

    }

    // KEY DOESN'T EXIST
    return NULL;
}

void test( Node *root, int key ) {

    Node *res = nextRight( root, key );

    if( res )
        cout << " Next Right : " <<  res -> data;
    else
        cout << " No Next Right" ;

    cout << "\n";
}

int solve( Node *root, int val ) {

    if( root == NULL )
        return 0;

    val = val * 10 + root -> data;

    if( root -> left == NULL && root -> right == NULL )
        return val;

    return solve( root -> left, val ) + solve( root -> right, val );
}

int treePathsSum( Node *root ) {

    return solve( root, 0 );

}

int main() {

    Node *root = new Node(6);
    root->left        = new Node(3);
    root->right       = new Node(5);
    root->left->left  = new Node(2);
    root->left->right = new Node(5);
    root->right->right = new Node(4);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    cout << treePathsSum( root ) ;

    return 0;
}




