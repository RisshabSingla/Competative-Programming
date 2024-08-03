#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

bool dfs(int node, vector<int> &team, vector<vector<ll>> &adjList)
{
    for (auto dost : adjList[node])
    {
        if (team[dost] == -1)
        {
            team[dost] = 3 - team[node];
            bool a = dfs(dost, team, adjList);
            if (!a)
            {
                return false;
            }
        }
        if (team[dost] + team[node] != 3)
        {
            return false;
        }
    }
    return true;
}

bool assignTeams(vector<int> &team, vector<vector<ll>> &adjList, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (team[i] == -1)
        {
            team[i] = 1;
            bool a = dfs(i, team, adjList);
            if (!a)
            {
                return false;
            }
        }
    }
    return true;
}

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

    vector<int> team(n, -1);
    bool ans = assignTeams(team, adjList, n);
    if (ans)
    {
        for (auto i : team)
        {
            cout << i << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE";
    }
    return 0;
}