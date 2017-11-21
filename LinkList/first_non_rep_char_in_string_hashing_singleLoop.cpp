#include <iostream>
#include <map>
using namespace std;
int main(){

    string inp;
    cin >> inp;

    map<char, pair<int,int> >freq;

    //m[char] = count,index

    for(int i=0;i<inp.size();i++) {
        freq[inp[i]].first++;
        if( freq[inp[i]].first == 1 ) {  // first occurence then store index
            freq[inp[i]].second = i;
        }
    }

// much better than prev approach since string can be very large so
// it is better to traverse hashmap

    map<char, pair <int,int> >::iterator it;
    for(it=freq.begin();it!=freq.end();it++) {
        if((it->second).first == 1) {
            cout << inp[(it->second).second] << endl;
            return 0;
        }
    }

    cout << "-1" <<endl;
    //all are repeating
    return 0;
}

