#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <cstdio>
using namespace std;

int main() {

    string inp,word,op;

    int t;
    cin >> t;

    getline(cin,inp);
    while ( t-- ) {

        getline(cin,inp);
        inp = inp + " ";

        for(int i=0;i<inp.size();i++) {

            if(inp[i] == ' ' ) {
                word[0] = toupper(word[0]);
                op = op + word + " ";
                word = "";
            }
            else
                word = inp[i] + word;
        }
        cout << op << endl;
        op = "";
    }

    return 0;
}
