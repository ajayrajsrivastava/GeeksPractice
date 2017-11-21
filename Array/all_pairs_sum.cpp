#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int main() {

    int t;
    int n,m,x;

    cin >> t;
    while( t-- ) {


        cin >> n >> m >> x;
        int arr1[n];
        int arr2[m];

        for( int i = 0 ; i < n; i++ ) {
            cin >> arr1[i];
        }

        for( int i = 0 ; i < m; i++ ) {
            cin >> arr2[i];
        }


        vector< pair<int,int> >p;

        for( int i = 0; i < n ; i++ ) {

            for( int j = 0 ; j < m ; j++ ) {

                if(arr1[i]+arr2[j] == x)
                {
                    p.push_back(make_pair(arr1[i],arr2[j]));

                }

            }

        }

        sort(p.begin(),p.end());

        if(p.size()!=0)
        {
        for(int i = 0 ; i < p.size() ; i++ ) {

            cout << p[i].first << " " << p[i].second << (i == p.size()-1 ? "" :",") << " ";
        }
        }
        else
            cout << "-1";

        cout << endl;
    }

    return 0;
}
