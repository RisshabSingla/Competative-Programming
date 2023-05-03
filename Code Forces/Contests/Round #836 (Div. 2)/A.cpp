#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;


int main()
{
    int cases;
    cin>>cases;
    while(cases--){
        string str;
        cin>>str;
        string rev = str;
        reverse(rev.begin(), rev.end());
        string output = str + rev;
        cout<<output<<endl;
    }
    return 0;
}
