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
    int n,m;

    cin >> t;
    while( t-- ) {

        cin >> m >> n;

        for( int i = m; i <=n ; i++ ) {

            std::ostringstream ss;
            ss << i;
            if ( check( ss.str() ) )
                cout << i << " ";

        }
        cout << endl;

    }
    return 0;
}


