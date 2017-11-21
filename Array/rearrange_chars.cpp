#include<iostream>
#include<set>
#include<algorithm>
#include<sstream>
using namespace std;

bool check( string str) {

    set<int>s;
    int len = str.length();

    for(int i = 0 ;i < len ; i++ ) {
        s.insert(str[i]);
    }
    if(s.size()!=len)
        return false;

    return true;

}

int main() {

    int t;
    string str;

    cin >> t;
    while( t-- ) {

        set<int>s;
        cin >> str;

        for( int i = 0; i <=str.size() ; i++ ) {
            s.insert(str[i]);
        }

        cout << endl;

    }
    return 0;
}



