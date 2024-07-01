#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>
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
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

        ll prev = arr[0];
        unordered_map<ll, ll> mp;
        for (ll i = 1; i < n; i++)
        {
            ll t = max(prev, arr[i]);
            prev = max(prev, arr[i]);
            mp[t - arr[i]]++;
        }
        ll total = 0;
        for (auto i : mp)
        {
            if (i.first == 0)
            {
                continue;
            }
            // cout << "Pushing: " << i.first << " " << i.second << "\n";
            pq.push({i.first, i.second});
            total += i.second;
        }

        ll ans = 0;
        ll sub = 0;
        while (!pq.empty())
        {
            pair<ll, ll> top = pq.top();
            // cout << "TOp is: " << top.first << " " << top.second << "\n";
            pq.pop();
            if (top.first - sub <= 0)
            {
                continue;
            }
            ans += ((top.first - sub) * (total + 1));
            total -= top.second;
            // cout << "Adding: " << ((top.first - sub) * (pq.size() + top.second + 1)) << "\n";
            sub += (top.first - sub);
        }
        cout << ans << "\n";
    }
    return 0;
}
