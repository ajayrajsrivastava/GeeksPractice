#include <iostream>
#include <map>
using namespace std;
int main(){

    string inp;
    cin >> inp;

    map<char,int>freq;

    //using two loops and a hashmap

    for(int i=0;i<inp.size();i++) {
        freq[inp[i]]++;
    }


    for(int i=0;i<inp.size();i++) {
        if( freq[inp[i]] == 1 ) {
            cout << inp[i] << endl;
            return 0;
        }
    }

    return 0;
}
