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
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        unordered_map<ll, vector<ll>> mp;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i]].push_back(i + 1);
        }
        ll minSize = INT_MAX;
        ll number = -1;
        if (mp.size() == 1)
        {
            cout << "NO\n";
            continue;
        }
        for (auto &i : mp)
        {
            if (i.second.size() < minSize)
            {
                minSize = i.second.size();
                number = i.first;
            }
        }
        cout << "YES\n";
        // cout << minSize << "\n";
        vector<ll> indexes = mp[number];
        int index1 = indexes[0];
        unordered_map<ll, ll> nodes;
        for (auto i : indexes)
        {
            nodes[i]++;
        }
        for (auto &i : mp)
        {
            if (i.first == number)
            {
                continue;
            }
            for (auto j : i.second)
            {
                cout << index1 << " " << j << "\n";
                // cout << j << " " << index1 << "\n";
            }
        }
        for (int i = 1; i < indexes.size(); i++)
        {
            for (ll j = 1; j <= n; j++)
            {
                if (!nodes.count(j))
                {
                    cout << indexes[i] << " " << j << "\n";
                    // nodes[j]++;
                    break;
                }
            }
        }

        // cout << "\n";
    }

    return 0;
}