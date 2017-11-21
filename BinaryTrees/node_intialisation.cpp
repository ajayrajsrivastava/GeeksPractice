#include<iostream>
using namespace std;

/*
    In C++ the only difference between a class and a struct is that
    members and base classes are private by default in classes,
    whereas they are public by default in structs.
    */

struct node{

    int data = 10; // default
    node *left  = NULL;
    node *right = NULL;

    node( int data ) {

        this -> data = data;

    }


};


int main() {

    node *root = new node(1);
    cout << root -> data;
    return 0;
}
