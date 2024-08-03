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
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adjList(n);

    vector<ll> inDegrees(n, 0);
    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        adjList[a - 1].push_back(b - 1);
        inDegrees[b - 1]++;
    }
    queue<ll> q;
    vector<ll> ans;
    for (ll i = 0; i < n; i++)
    {
        if (inDegrees[i] == 0)
        {
            q.push(i);
            ans.push_back(i);
        }
    }

    while (!q.empty())
    {
        ll node = q.front();
        q.pop();
        for (auto edge : adjList[node])
        {
            inDegrees[edge]--;
            if (inDegrees[edge] == 0)
            {
                ans.push_back(edge);
                q.push(edge);
            }
        }
    }

    if (ans.size() == n)
    {
        for (auto i : ans)
        {
            cout << i + 1 << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE";
    }

    return 0;
}