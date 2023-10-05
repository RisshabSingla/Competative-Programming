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

ll gcd(ll a, ll b){
    if(b == 0){
        return a;
    }
    return gcd(b, a%b);
}

ll findLeast(ll num){
    for(ll i = 2; i<=sqrt(num); i++){
        if(num%i == 0){
            return i;
        }
    }
    return -1;
}
int main()
{
    int cases;
    cin>>cases;
    while(cases--){
        ll left;
        ll right;
        cin>>left>>right;
        if(left == right && left!= 1){
            ll least = findLeast(left);
            // cout<<least<<endl;
            ll a = least;
            ll b = left-least;
            
            if(a> 0 && b> 0 && gcd(a,b) != 1){
                cout<<a<<" "<<b<<endl;
                continue;
            }
        }
        ll a = (left+1)/2;
        ll b = (left+1)/2;
        if(a!= 1LL && b!= 1LL && left<= a+b && a+b<=right){
            cout<<a<<" "<<b<<endl;
            continue;
        }
        a = (right)/2;
        b = (right)/2;
        if(a!= 1LL && b!= 1LL && left<= a+b && a+b<=right){
            cout<<a<<" "<<b<<endl;
            continue;
        }

        ll mid = (left+right)/2;
        a = max(mid, 2LL);
        b = max(mid, 2LL);
        if(left<= a+b && a+b<=right){
            cout<<a<<" "<<b<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
    return 0;
}
