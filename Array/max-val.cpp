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
        int a[n];

        for( int i = 0 ; i < n; i++ )
            cin >> a[i];

        int val = -1;

        for( int i = 0 ; i <= n-1; i ++ )
        {
            for( int j = 0 ; j <= n-1; j++) {

                    if(i!=j)
                        val = max(val,(a[i]-i)-(a[j]-j));

            }

        }
        cout << val << endl;
    }
    return 0;
}




