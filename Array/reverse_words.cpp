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

        string s,rev,ans;
        cin >> s;

        s = s + ".";

        for(int i = 0; i < s.length(); i++ ){

            if(s[i] == '.') {
                ans = (i == s.length()-1 ? "" : ".") + rev + ans ;
                rev = "";
            }
            else
                rev = rev + s[i];

        }

        cout << ans << endl;
    }

    return 0;
}

