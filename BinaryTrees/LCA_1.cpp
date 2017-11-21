#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

struct Node{

    int data;
    Node *left  = NULL;
    Node *right = NULL;
    Node( int data ) {
        this -> data = data;
    }
};

bool findPath( Node *root, vector<int> &path, int key ) {

    if( root == NULL )
        return false;

    path.push_back( root -> data );

    if( root -> data ==  key )
        return true;

    if( findPath( root -> left, path, key ) || findPath( root -> right, path, key )  )
        return true;


    path.pop_back();
    return false;
}

int findLCA( Node *root, int n1, int n2 ) {

    vector<int> path1,path2;

    //RETURN -1 IF EITHER N1 OR N2 IS NOT PRESENT
    if( !findPath( root, path1, n1) || !findPath( root, path2, n2) )
        return -1;

    /*
    for( int i = 0; i < path1.size(); i ++ )
        cout << path1[i] << " " ;

    cout << endl;

    for( int i = 0; i < path2.size(); i ++ )
        cout << path2[i] << " " ;

    cout << endl;
    */

    int i;
    for( i = 0; i < path1.size() && i < path2.size(); i++ ) {
        if( path1[i] != path2[i] )
            break;
    }
    return path1[i-1];
}

int main() {

    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5) << endl;
    cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6) << endl;
    cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4) << endl;
    cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4) << endl;

    //NONE PRESENT
    cout << "\nLCA(2, 11) = " << findLCA(root, 2, 11);
    //ONE PRESENT
    cout << "\nLCA(100, 104) = " << findLCA(root, 100, 104);

    return 0;
}
