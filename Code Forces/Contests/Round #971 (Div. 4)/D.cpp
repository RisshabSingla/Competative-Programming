#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        unordered_map<ll, ll> mp0;
        unordered_map<ll, ll> mp1;
        ll oneCount = 0;
        ll zeroCount = 0;
        for (ll i = 0; i < n; i++)
        {
            ll a, b;
            cin >> a >> b;
            if (b == 1)
            {
                mp1[a]++;
                oneCount++;
            }
            else
            {
                mp0[a]++;
                zeroCount++;
            }
        }

        ll count = 0;
        for (auto i : mp0)
        {
            if (mp1.count(i.first))
            {
                // straight line formed
                count += (zeroCount - 1);
            }
            if (mp1.count(i.first - 1) && mp1.count(i.first + 1))
            {
                count++;
            }
        }
        for (auto i : mp1)
        {
            if (mp0.count(i.first))
            {
                // straight line formed
                count += (oneCount - 1);
            }
            if (mp0.count(i.first - 1) && mp0.count(i.first + 1))
            {
                count++;
            }
        }
        cout << count << "\n";
    }
    return 0;
}
