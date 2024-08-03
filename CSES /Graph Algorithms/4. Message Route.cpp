#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adjList(n);
    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    vector<ll> prev(n, -1);
    prev[0] = 0;
    queue<ll> q;
    q.push(0);
    while (!q.empty())
    {
        ll node = q.front();
        q.pop();
        for (auto i : adjList[node])
        {
            if (prev[i] == -1)
            {
                q.push(i);
                prev[i] = node;
            }
        }
    }
    if (prev[n - 1] == -1)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> ans;
    ll node = n - 1;
    while (prev[node] != node)
    {
        ans.push_back(node + 1);
        node = prev[node];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}