#include<iostream>
using namespace std;

const int N = 50;

struct Node {

    char data;
    unsigned isEndOfString = 1;
    Node *left  = NULL;
    Node *eq    = NULL;
    Node *right = NULL;

    Node( char data ) {

        this -> data  = data;
        isEndOfString = 0;
    }
};


void insert( Node **root, char *word ) {


    if( (*root) == NULL )
        (*root) = new Node( (*word) );

    if( (*word) < (*root) -> data )
        insert( &( (*root) -> left ), word );

    else if( (*word) > (*root) -> data )
        insert( &( (*root) -> right ), word );


    else // equal
    {

        if( *(word + 1) )
            insert( &((*root) -> eq), word + 1 );

        else // last char of word that is '\0'
            (*root) -> isEndOfString = 1;
    }

}

void traverseTSTUtil( Node *root, char *buffer, int depth ) {


    if( root == NULL )
        return;

    traverseTSTUtil( root -> left, buffer, depth );

    buffer[depth] = root -> data;

    if( root -> isEndOfString ) {

        buffer[depth+1] = '\0';
        cout << buffer << " ";

    }

    traverseTSTUtil( root -> eq, buffer, depth + 1 );
    traverseTSTUtil( root -> right, buffer, depth  ); // from 0th index

}

void traverseTST( Node *root ) {

    char buffer[N];
    traverseTSTUtil( root, buffer, 0 );

}


int searchTST( Node *root, char *word ) {

    if( root == NULL )
        return 0;

    if( (*word) < (root) -> data )
        return searchTST( root -> left, word );

    else if ( (*word) > (root) -> data )
        return searchTST( root -> right, word );

    else {

        if( *(word + 1) == '\0' )
            return root -> isEndOfString;

        return searchTST( root -> eq, word + 1 );
    }

}


int main() {

    Node *root = NULL;

    insert( &root, "cat"  );
    insert( &root, "cats" );
    insert( &root, "up"   );
    insert( &root, "bug"  );

    cout << "Traversal of Ternary Search Tree : ";
    traverseTST( root );

    cout << endl << "Search Results on TST: " << endl;

    searchTST( root, "cats" )? cout << "Found" << endl : cout << "Not Found " << endl;
    searchTST( root, "bu"   )? cout << "Found" << endl : cout << "Not Found " << endl;
    searchTST( root, "cat"  )? cout << "Found" << endl : cout << "Not Found " << endl;

    return 0;
}
