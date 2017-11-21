#include<iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--) {

        int n,p;
        cin >> n >> p;

        int arr[n];
        for(int i = 0;i < n;i++){
            cin >> arr[i];
        }


        int flag = 0;
        for(int i = 0;i < n-1;i++)
        {
            for(int j = i+1; j<n;j++)
            {
                if(arr[i] * arr[j] == p)
                {
                    cout << "Yes" << endl;;
                    flag = 1;
                    break;
                }
            }

            if(flag)
                break;
        }

        if (flag)
            continue;
        else
            cout << "No" << endl;
    }
   //0.085
    return 0;
}
