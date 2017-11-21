#include<iostream>
using namespace std;

struct Node {

    char data;
    Node *left  = NULL;
    Node *right = NULL;

    Node( char data ) {

        this -> data = data;
    }

};


Node* buildTree( string in, string pre, int inStart, int inEnd ) {


    static int preIndex = 0;

    if( inStart > inEnd )
        return NULL;

    Node *tNode = new Node( pre[preIndex++] );

    if( inStart == inEnd ) //no children ie leaf
        return tNode;

    int inIndex = in.substr(inStart,inEnd + 1).find( tNode -> data );

    tNode -> left  = buildTree( in, pre, inStart,     inIndex - 1 );
    tNode -> right = buildTree( in, pre, inStart + 1, inIndex     );

    return tNode;
}

int main() {

    string in  = "DBEAFC";
    string pre = "ABDECF";

    Node *root = buildTree(in,pre,0, in.size() - 1 );


    return 0;
}
