#include<iostream>
#include<map>
#include<math.h>
#include<algorithm>

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

int main() {

    fast;
    int t;
    cin >> t;
    map<int,int>freq;
    while( t-- ) {

        int n;
        cin >> n;

        int a[n];
        long long int sum  = 0;

        int mode = 0;
        double mean = 0;
        double median = 0;


        for( int i=0;i<n;i++)
        {
            cin >> a[i];
            sum+=a[i];
            freq[a[i]]++;
        }

        sort(a,a+n);
        int maxf = 0;
        for(int i=0;i<n;i++) {

            if ( freq[a[i]] >= maxf ) {

                maxf = freq[a[i]];
                mode = min(mode,a[i]);
            }
        }

        mean = ((double)sum)/(double)n;


        if(n%2 == 0)
            median =  (double) (0.5 * (a[n/2] + a[(n/2)-1]));
        else
            median = (double)a[n/2];

        cout << (int)(round(mean)) << " " << (int)(round(median)) << " " << mode << endl;

        freq.clear();
    }

}
