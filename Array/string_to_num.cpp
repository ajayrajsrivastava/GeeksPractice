#include<iostream>
#include<sstream>
using namespace std;

int main() {

    int x;
    string s;

    /* number to string
    cin >> x;

    ostringstream ss;
    ss << x;

    cout << ss.str() << endl;
    */

    //string to num

    cin >> s;

    istringstream ss(s);
    ss >> x;

    cout << x ;
    return 0;
}
