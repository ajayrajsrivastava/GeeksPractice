#include<iostream>
#include<algorithm>
#include<string.h>
#include<map>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--) {

        char s;string ans;

        int x = 0;
        int o = 0;

        for(int i = 0 ;i < 9 ;i ++) {
            cin >> s;
            if(s == 'X')
                x++;
            else
                o++;
        }

        if(x<4 || x>5 || o<4 || o>5)
            ans = "Invalid";
        else
            ans = "Valid";

        cout << ans << endl;
    }

    return 0;
}


