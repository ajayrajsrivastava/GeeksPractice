#include <iostream>
#include <vector>
#include <map>
using namespace std;

// TLE

int n;
void firstNonRep(string substream) {
    map<char,pair<int,int> >freq;

    for(int i=0;i<substream.size();i++) {
        freq[substream[i]].first++;
        if( freq[substream[i]].first == 1) {
             freq[substream[i]].second = i;
        }
    }

    map<char,pair<int,int> >::iterator it;

    for(it=freq.begin();it!=freq.end();it++) {
        if((it->second).first == 1) {
            cout << substream[(it->second).second] << " ";
            return ;
        }
    }

    cout << "-1" << " ";
    return ;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while ( t-- ) {
        cin >> n;
        string stream;

        for(int i = 0 ; i < n; i++) {
            char inp;
            cin >> inp;
            if(inp != ' ')
                stream.push_back(inp);
        }

        for(int i=0;i<stream.size();i++) {

            firstNonRep(stream.substr(0,i+1));

        }

        cout << endl;
    }

}
