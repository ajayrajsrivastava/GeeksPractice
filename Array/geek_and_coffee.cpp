#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int main() {

    int t;
    int n,m;

    cin >> t;
    while( t-- ) {

        cin >> n >> m;

        for( int i = 1; i < m && n!=0 ; i++ ) {
            n/=2;
        }

        cout << n << endl;

    }
    return 0;
}

