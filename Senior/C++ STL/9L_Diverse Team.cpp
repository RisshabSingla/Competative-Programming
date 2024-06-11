#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    ll n, k;
    cin >> n >> k;
    unordered_map<ll, vector<ll>> mp;
    ll t;

    for (ll i = 0; i < n; i++)
    {
        cin >> t;
        mp[t].push_back(i + 1);
    }
    if (mp.size() < k)
    {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    vector<ll> ans;
    for (auto i : mp)
    {
        if (k == 0)
        {
            break;
        }
        ans.push_back(i.second[0]);
        // cout << i.second[0] << " ";
        k--;
    }
    sort(ans.begin(), ans.end());
    for (auto &i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}