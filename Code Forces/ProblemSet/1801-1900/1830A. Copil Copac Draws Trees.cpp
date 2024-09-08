#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<pll> vpl;
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
        vector<pll> arr(n - 1);
        vector<ll> dist(n - 1, LLONG_MAX);
        queue<ll> q;
        vector<set<ll>> pendingEdges(n);
        vector<bool> done(n, false);
        for (ll i = 0; i < n - 1; i++)
        {
            cin >> arr[i].first >> arr[i].second;
            arr[i].first--;
            arr[i].second--;
            pendingEdges[arr[i].first].insert(i);
            pendingEdges[arr[i].second].insert(i);
            if (arr[i].first == 0 || arr[i].second == 0)
            {
                q.push(i);
                dist[i] = 1;
            }
        }

        done[0] = true;

        while (!q.empty())
        {
            ll currIndex = q.front();
            q.pop();
            ll node = arr[currIndex].first;
            if (done[node])
            {
                node = arr[currIndex].second;
                if (done[node])
                {
                    continue;
                }
            }
            done[node] = true;
            for (auto index : pendingEdges[node])
            {
                if (index < currIndex)
                {
                    q.push(index);
                    dist[index] = dist[currIndex] + 1;
                }
                else
                {
                    q.push(index);
                    dist[index] = dist[currIndex];
                }
            }
        }

        ll ans = 0;
        for (auto i : dist)
        {
            ans = max(ans, i);
        }
        cout << ans << "\n";
        // set<ll> done;
        // done.insert(1);
        // ll count = 0;
        // while (done.size() < n)
        // {
        //     for (auto i : arr)
        //     {
        //         if (done.count(i.first) || done.count(i.second))
        //         {
        //             done.insert(i.first);
        //             done.insert(i.second);
        //         }
        //     }
        //     // cout << "Set is: ";
        //     // for (auto i : done)
        //     // {
        //     //     cout << i << " ";
        //     // }
        //     // cout << "\n";
        //     count++;
        // }
        // cout << count << "\n";
    }
    return 0;
}