#include<iostream>


using namespace std;

const string alpha[] = {"", "a", "b", "c", "d", "e","f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r","s", "t", "u", "v", "w", "x", "v", "z"};

struct Node{

    string data;
    Node *left;
    Node *right;

    Node( string data ) {

        this -> data = data;
    }

    string getDataString() {
        return data;
    }
};



Node* createTree( int data, string parString, int arr[] ) {

    if( data > 26 )
        return NULL;

    string nodeString = parString + alpha[ data ];
    Node *root = new Node( nodeString );


    int len = sizeof(arr)/sizeof(arr[0]);

    if( len !=0 ) {

        data  = arr[0];


        cout << len ;

        int newArr[ len - 1 ];
        copy( arr + 1, arr + len, newArr );

        root -> left = createTree( data, nodeString, newArr );

        if( len > 1) {

             data = arr[0]*10 + arr[1];

             int newArr[ len - 2 ];
             copy( arr + 2, arr + len, newArr );

             root -> right = createTree( data, nodeString, newArr );
        }

    }

    return root;

}



void printInterpretations( int arr[] ) {

    //Step 1 : Create Tree
    Node *root = createTree( 0, "", arr );

}

int main() {


    int arr[] = {1,2,1};
    printInterpretations( arr );

    return 0;
}

