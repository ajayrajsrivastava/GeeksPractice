#include<iostream>
#include<set>
#include<algorithm>
#include<sstream>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    int n;

    cin >> t;
    while( t-- ) {

        cin >> n;
        int inp;


        int val = 0;

        for( int i = 0 ; i < n; i++ )
            {
            cin >> inp;
            val = val ^ inp;
            }


        cout << val << endl;
    }
    return 0;
}





