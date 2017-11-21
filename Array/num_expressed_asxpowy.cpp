#include<iostream>
#include<set>
#include<algorithm>
#include<sstream>
using namespace std;

bool solve(int x)
{
    set<int>s;
   for(int i=2;i<=x;i++) {

        if(x%i == 0)
        {
            x=x/i;
            s.insert(i);
        }
   }

    if(s.size() == 1)
        return false;

    return true;

}

int main() {

    int t;
    int n;

    cin >> t;
    while( t-- ) {

        cin >> n;
        cout << (solve(n)?"0":"1") << endl;


    }
    return 0;
}



