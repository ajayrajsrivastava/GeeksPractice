#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--) {

        int n;
        cin >> n;

        int sum = n*(n+1)/2;
        n-=1;
        int s = 0;
        for(int i = 1;i <= n;i++){
            int x;
            cin >> x;
            s+=x;
        }
        cout << sum - s << endl;

    }
   //0.135
    return 0;
}
