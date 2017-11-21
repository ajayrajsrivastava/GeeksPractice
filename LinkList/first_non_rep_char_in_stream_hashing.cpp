#include <iostream>
#include <vector>
#include <map>
using namespace std;

// TLE

int n;
void firstNonRep(string substream) {
    map<char,int>freq;

    for(int i=0;i<substream.size();i++) {
        freq[substream[i]]++;
    }

    for(int i=0;i<substream.size();i++) {
        if(freq[substream[i]] == 1) {
            cout << substream[i] << " ";
            return ;
        }
    }

    cout << "-1" << " ";
    return ;

}

int main() {

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
