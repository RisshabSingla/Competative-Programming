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

void getPrefix(vector<vector<ll>> &pref, string &str, ll n)
{
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j < 26; j++)
        {
            pref[i][j] += pref[i - 1][j];
        }
        pref[i][str[i - 1] - 'a']++;
    }
}

vector<ll> getDiff(vector<vector<ll>> &pref, ll left, ll right)
{
    vector<ll> diff(26);
    for (ll i = 0; i < 26; i++)
    {
        diff[i] = pref[right][i];
    }
    for (ll i = 0; i < 26; i++)
    {
        diff[i] -= pref[left - 1][i];
    }
    return diff;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n, q;
        cin >> n >> q;
        string a, b;
        cin >> a >> b;
        vector<vector<ll>> pref1(n + 1, vector<ll>(26, 0));
        vector<vector<ll>> pref2(n + 1, vector<ll>(26, 0));

        getPrefix(pref1, a, n);
        getPrefix(pref2, b, n);

        // for (auto i : pref1)
        // {
        //     for (auto j : i)
        //     {
        //         cout << j << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << '\n';

        while (q--)
        {
            ll l, r;
            cin >> l >> r;
            vector<ll> diff1 = getDiff(pref1, l, r);
            vector<ll> diff2 = getDiff(pref2, l, r);
            ll count = 0;
            for (ll i = 0; i < 26; i++)
            {
                count += abs(diff1[i] - diff2[i]);
            }
            cout << count / 2 << "\n";
            // for (auto i : diff1)
            // {
            //     cout << i << " ";
            // }
            // cout << "\n";
            // // cout << "\n";
            // for (auto i : diff2)
            // {
            //     cout << i << " ";
            // }
            // cout << "\n";
            // cout << "\n";
        }
        // cout << "\n";
    }
    return 0;
}
