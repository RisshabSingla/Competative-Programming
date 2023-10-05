#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

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

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n, x, y;
        cin >> n >> x >> y;
        if (x == y)
        {
            cout << 0 << endl;
            continue;
        }
        // ll pos_sum = 0;
        // ll neg_sum = 0;
        // ll num = n;
        // // unordered_map<ll, ll> mapping;
        // for (ll i = x; i <= n; i += x)
        // {
        //     if (i % y == 0)
        //     {
        //         continue;
        //         // mapping[i] = num;
        //     }
        //     // cout << "Adding num: " << num << endl;
        //     pos_sum += num;
        //     num--;
        // }

        // // for (ll i = x; i <= n; i += x)
        // // {
        // //     if (i % y == 0)
        // //     {
        // //         mapping[i] = num;
        // //         // cout << "Adding num: " << num << endl;
        // //         pos_sum += num;
        // //         num--;
        // //     }
        // // }

        // num = 1;
        // for (ll i = y; i <= n; i += y)
        // {
        //     if (i % x != 0)
        //     {
        //         neg_sum += num;
        //         num++;
        //     }
        // }

        // ll pos = n;
        // ll neg = 1;
        // for(ll i = 1; i<=n; i++){
        //     if(i%x == 0 && i%y != 0){
        //         pos_sum += pos;
        //         pos--;
        //     }
        //     if(i%y == 0 && i%x != 0){
        //         neg_sum+= neg;
        //         neg++;
        //     }
        // }

        // ll pos = n;
        // ll neg = 1;
        // ll i = x;
        // ll j = y;
        // while (i <= n && j <= n)
        // {
        //     if (i % y != 0)
        //     {
        //         pos_sum += pos;
        //         pos--;
        //     }
        //     i += x;
        //     if (j % x != 0)
        //     {
        //         neg_sum += neg;
        //         neg++; 
        //     }
        //     j += y;
        // }

        // while (i <= n)
        // {
        //     if (i % y != 0)
        //     {
        //         pos_sum += pos;
        //         pos--;
        //     }
        //     i += x;
        // }

        // while(j <= n){
        //     if (j % x != 0)
        //     {
        //         neg_sum += neg;
        //         neg++; 
        //     }
        //     j += y;
        // }

        // cout << pos_sum - neg_sum << endl;

        ll GCD = gcd(x,y);
        ll lcm = (x*y)/GCD;
        ll common = n/lcm;
        ll pos = n/x - common;
        ll neg = n/y - common;
        ll pos_sum = (n)*(n+1)/2 - (n-pos)*(n-pos+1)/2;
        ll neg_sum = (neg)*(neg+1)/2;
        // cout<<pos_sum<<" "<<neg_sum<<endl;
        cout<<pos_sum-neg_sum<<endl;

    }
    return 0;
}
