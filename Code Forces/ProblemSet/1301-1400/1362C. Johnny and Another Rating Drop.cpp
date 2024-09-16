#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<pll> vpl;
typedef vector<int> vi;

const int mod = 1000000007;

ll findAns(ll n)
{
    if (n == 0)
    {
        return n;
    }
    return n + findAns(n / 2);
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        // ll ans = 0;
        // while (n > 0)
        // {
        //     ll num = log2(n);
        //     ll add = (1LL << (num + 1));
        //     // cout << "Adding: " << add << "\n";
        //     ans += (add - 1);
        //     n -= (1LL << num);
        // }

        cout << findAns(n) << "\n";
    }
    return 0;
}