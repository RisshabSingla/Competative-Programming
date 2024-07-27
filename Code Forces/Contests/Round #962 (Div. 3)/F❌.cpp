#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
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
        ll n, k;
        cin >> n >> k;
        vector<pair<ll, ll>> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i].first;
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i].second;
        }

        // priority_queue<pair<ll, ll>> pq;
        // for (auto &i : arr)
        // {
        //     pq.push(i);
        // }
        // ll score = 0;
        // while (!pq.empty() && k--)
        // {
        //     pair<ll, ll> top = pq.top();
        //     pq.pop();
        //     score += top.first;
        //     if (top.first > top.second)
        //     {
        //         pq.push({top.first - top.second, top.second});
        //     }
        // }
        // cout << score << "\n";
    }
    return 0;
}
