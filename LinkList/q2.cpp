#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arrayMode(std::vector<int> sequence) {

   // sort(sequence.begin(),sequence.end())
    int max = -1;
    int cnt ;
    for(int i=0;i<sequence.size();i++)
    {
        int cnt = count(sequence.begin(),sequence.end(),sequence[i]);
        cout<< sequence[i] <<" "<<cnt <<endl;
        if (cnt>max)
            max = cnt;

    }
    return max;
}

int main()
{
vector<int> seq;
for(int i =0;i<4;i++)
{
int x;
cin >> x;
seq.push_back(x);
}
 cout<<arrayMode(seq)<<endl;

}
