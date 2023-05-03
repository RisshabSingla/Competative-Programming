#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
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
        ll l;
        ll r;
        ll x;
        ll a;
        ll b;
        cin>>l>>r>>x>>a>>b;
        if(a==b){
            cout<<0<<endl;
            continue;
        }
        int diff = r-l;
        if(diff < x){
            cout<<-1<<endl;
            continue;
        }
        unordered_map<int,int> present;

        int temp = a;
        

    }
    return 0;
}