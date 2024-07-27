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

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        string str;
        cin >> str;

        ll n = str.length();
        vector<ll> pref(n + 1, 0);
        ll sum = 0;
        for (ll i = 0; i < n; i++)
        {
            if (str[i] == '1')
            {
                sum++;
            }
            else
            {
                sum--;
            }
            pref[i + 1] = sum;
        }

        map<ll, ll> mp;
        ll count = 0;

        for (ll i = 0; i <= n; i++)
        {
            ll left = pref[i];
            ll sumL = mp[left];
            ll right = n - i + 1;
            count += ((right * sumL) % mod);
            mp[left] += (i + 1);
        }
        count %= mod;
        cout << count << "\n";
    }
    return 0;
}
