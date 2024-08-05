#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

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
        ll n, k;
        cin >> n >> k;
        vector<ll> arr(n);
        unordered_map<ll, ll> mp;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i] % k]++;
        }
        ll count = 0;
        for (auto i : mp)
        {
            if (i.first == 0)
            {
                count++;
                continue;
            }
            if (!mp.count(k - i.first))
            {
                count += i.second;
                continue;
            }
            if (i.first == k - i.first)
            {
                count++;
                continue;
            }
            if (k - i.first > i.first)
            {
                ll a = i.second;
                ll b = mp[k - i.first];
                if (abs(a - b) <= 1)
                {
                    count++;
                }
                else
                {
                    count += abs(b - a);
                }
            }
        }
        // for (int i = 1; i <= k / 2; i++)
        // {
        //     if (i == k - i && mp[i])
        //     {
        //         count++;
        //         continue;
        //     }
        //     ll first = mp[i];
        //     ll second = mp[k - i];
        //     if (first == 0 || second == 0)
        //     {
        //         count += max(first, second);
        //         continue;
        //     }
        //     ll mini = min(first, second);
        //     count += max(first - mini - 1, second - mini - 1);
        //     count += mini;
        // }
        cout << count << '\n';
    }
    return 0;
}