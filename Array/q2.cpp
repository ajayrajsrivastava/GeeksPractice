#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll int todigit( string s) {

    ll int n;
    istringstream ss(s);
    ss >> n;

    return n;
}

int main() {

    fast;
    ll int t;
    cin >> t;

    while( t-- ) {

        string s1 = "";
        string s2 = "";
        string s3 = "";

        cin >> s1 >> s2 >> s3;

        string dig1="";
        string dig2="";
        string dig3="";
        string dig4="";
        string dig5="";

        ll int a,b,c,d,e;

        ll int i = 1;

                while(s1[i]!='/')
                    {
                        dig1=dig1+s1[i];
                        i++;
                    }

                    //cout << dig1 << endl;

                    i++;

                    int len1 = s1.size();
                    dig2 = s1.substr(i,len1);

        i = 0;

                     while(s3[i]!='/')
                    {
                        dig3=dig3+s3[i];
                        i++;
                    }

                    i++;
                    //cout << dig3 << endl;

                     while(s3[i]!=')')
                    {
                        dig4=dig4+s3[i];
                        i++;
                    }
                    i+=2;

                   // cout << dig4 << endl;

                    int len3 = s3.size();
                    dig5 = s3.substr(i,len3);

                    //cout << dig5 << endl;



        a = todigit(dig1);
        b = todigit(dig2);
        c = todigit(dig3);
        d = todigit(dig4);
        e = todigit(dig5);

        ll int num = (a*d + b*c);
        ll int den = b*d*e;
        cout << num << " " << den << endl;

        }

    return 0;

}
