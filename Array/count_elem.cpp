#include<iostream>
#include<algorithm>
using namespace std;

int main() {

    int t;

    cin >> t;

    while( t-- ) {

        int n;

        cin >> n;
        int a[n],b[n];

        for( int i = 0; i < n; i++ )    cin >> a[i];
        for( int i = 0; i < n; i++ )    cin >> b[i];

        sort(b,b+n);

        for(int i = 0; i < n; i++ ) {

            int c = 0;
            for( int j = 0; j < n; j++ )
            {
                if(b[j] <= a[i])    c++;
            }

            cout << c << ((i == n-1)?"":",");
        }
            cout << endl;
    }

}
