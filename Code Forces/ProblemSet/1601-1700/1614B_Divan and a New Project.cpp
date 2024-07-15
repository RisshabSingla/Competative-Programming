#include <iostream>
#include <vector>
#include <algorithm>
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
        vector<ll> indexes(n + 1, -1);
        priority_queue<pair<ll, ll>> pq;
        ll center = (n + 1) / 2;
        for (ll i = 0; i < n; i++)
        {
            ll t;
            cin >> t;
            pq.push({t, i + 1});
        }
        indexes[0] = center;
        ll index = 1;
        ll cost = 0;
        while (!pq.empty())
        {
            pair<ll, ll> top = pq.top();
            pq.pop();
            indexes[top.second] = center - index;
            cost += (2 * (top.first) * abs(indexes[top.second] - indexes[0]));
            if (!pq.empty())
            {
                pair<ll, ll> top2 = pq.top();
                pq.pop();
                indexes[top2.second] = center + index;
                cost += (2 * (top2.first) * abs(indexes[top2.second] - indexes[0]));
            }
            index++;
        }
        cout << cost << "\n";
        for (auto i : indexes)
        {
            cout << i << ' ';
        }
        cout << "\n";
    }
    return 0;
}