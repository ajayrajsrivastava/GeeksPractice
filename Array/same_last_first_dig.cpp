#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--) {

        int cnt = 0;
        int l,r;

        cin >> l >> r;

        for( int i = l; i <= r ; i++ ) {
        std::ostringstream ss;
        ss << i;
        string s = ss.str();
        if( s[0] == s[s.length()-1])
            cnt++;
        }

        cout << cnt << endl;
    }

    return 0;
}


