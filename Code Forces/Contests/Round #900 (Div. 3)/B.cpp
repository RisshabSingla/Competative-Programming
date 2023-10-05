#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<cmath>

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
        int n;
        cin>>n;
        int index = 5;
        for(int i = 0; i<n; i++){
            cout<<index<<" ";
            index++;
        }
        cout<<endl;
    }
    return 0;
}
