#include<iostream>
using namespace std;


struct node{

    int data;
    struct node *left;
    struct node *right;
};

int main(){

    int x = NULL;

 //   cout << x << endl;
 //   cout << !x << endl;

/*

    struct node *xx = NULL; xx-> data = 1 ; xx-> left = NULL; xx-> right = NULL;
    struct node *yy = NULL; yy-> data = 1 ; yy-> left = NULL; yy-> right = NULL;


    struct node *a = NULL; a-> data = 1 ; a-> left = NULL; a-> right = NULL;
    struct node *b = NULL; b-> data = 1 ; b-> left = NULL; b-> right = NULL;


    a -> left = xx;
    b -> left = yy;
*/

    cout << (!NULL ||  NULL) << endl;
    cout << ( NULL || !NULL) << endl;
    cout << ( NULL ||  NULL) << endl;
    cout << (!NULL || !NULL) << endl;

    cout << (!NULL &  NULL) << endl;
    cout << ( NULL & !NULL) << endl;
    cout << ( NULL &  NULL) << endl;
    cout << (!NULL & !NULL) << endl;

 //   if( xx -> data == yy-> data )
 //       cout << "Yes" << endl;

    return 0;
}
