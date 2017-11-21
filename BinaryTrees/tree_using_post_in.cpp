#include<iostream>
using namespace std;

struct Node {

    int data;
    Node *left  = NULL;
    Node *right = NULL;

    Node( int data ) {

        this -> data = data;
    }

};

int search( int arr[], int key, int n ) {

    for( int i = 0; i < n; i ++ ) {

        if( arr[i] == key )
            return i;

    }

    return -1;

}

void postOrder( int in[], int pre[], int n ) {

    int root = search( in, pre[0], n );

    //IF LEFT SUB NOT EMPTY
    if( root != 0 )
        postOrder( in, pre + 1, root );

    //IF RIGHT SUB NOT EMPTY
    if( root != n-1 )
        postOrder( in + root + 1, pre + root + 1, n - root - 1 );

    cout << pre[0] << " ";
}

/*
~Similar Approach

if(inStart > inEnd) return;
    if(inStart == inEnd) {
        System.out.print(pre[preIndex++]+" ");
        return;
    }

    int index = search(inStart, inEnd, in, pre[preIndex++]);
    printPostOrder(inStart, index-1, in, pre);
    printPostOrder(index+1, inEnd, in, pre);
    System.out.print(in[index]+" ");

*/

int main() {

    int  in[]   = {4, 2, 5, 1, 3, 6};
    int  pre[] = {1, 2, 4, 5, 3, 6};

    int n =sizeof(in) / sizeof(in[0]);
    postOrder( in, pre, n );

    return 0;
}
