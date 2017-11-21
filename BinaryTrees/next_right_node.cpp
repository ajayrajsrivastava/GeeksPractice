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

int main() {

    Node *root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(6);
    root->right->right = new Node(5);
    root->left->left = new Node(8);
    root->left->right = new Node(4);

    test(root, 10);
    test(root, 2);
    test(root, 6);
    test(root, 5);
    test(root, 8);
    test(root, 4);

    return 0;
}



