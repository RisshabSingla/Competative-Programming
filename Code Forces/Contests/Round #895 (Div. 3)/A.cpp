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
        ll a,b,c;
        cin>>a>>b>>c;
        if(a == b){
            cout<<0<<endl;
            continue;
        }

        if(b>a){
            swap(a,b);
        }
        double mid = (a+b)/2.0;
        double max_diff = (abs(a-mid), abs(b-mid));
        double turns = max_diff/(double)c;
        cout<<ceil(turns)<<endl;

    }
    return 0;
}
