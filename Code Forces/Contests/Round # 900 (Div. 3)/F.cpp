#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int calcGCD(int a, int b){
    if(b == 0){
        return a;
    }
    return calcGCD(b, a%b);
}

ll calcDivisors(ll n){
    ll count = 0;
    for( ll i = 1; i<sqrt(n); i++){
        if(n% i == 0){
            count++;
        }
    }  
    return count+1;
}


bool checkPossible(ll n){
    ll a = -1;
    ll gcd = calcGCD(a,n);
    ll divisors = calcDivisors(n*gcd);

}

int main()
{
    ll cases;
    cin >> cases;
    while (cases--)
    {
        ll n,q;
        cin>>n>>q;
        ll original_n = n;
        while(q--){
            ll a;
            cin>>a;
            if(a == 1){
                ll x;
                cin>>x;
                n = n*x;
                if(checkPossible(n)){
                    cout<<"YES"<<endl;
                }else{
                    cout<<"NO"<<endl;
                }

            }else{
                n = original_n;
            }
        }
        cout<<endl;
    }
    return 0;
}