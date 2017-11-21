#include<iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--) {

        int n;
        cin >> n;

        int arr[n];
        for(int i = 0;i < n;i++){
            cin >> arr[i];
        }


    int mss = 0;
    int meh = 0;
    for(int i = 0; i < n ; i++ ) {

        mss+=arr[i];
        if(mss<0)
            meh = 0;

    }

    return 0;
}
