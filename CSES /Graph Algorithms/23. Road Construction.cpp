#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

class DisjointSet
{
    vector<ll> rank, parent;

public:
    ll highestRank;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 1);
        parent.resize(n + 1);
        highestRank = 0;
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    bool unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
        {
            return false;
        }

        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            rank[ulp_v] += rank[ulp_u];
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u] += rank[ulp_v];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u] += rank[ulp_v];
        }
        highestRank = max({highestRank, rank[ulp_u], rank[ulp_v]});
        return true;
    }
};

int main()
{
    ll n, m;
    cin >> n >> m;
    DisjointSet dsu(n);
    ll components = n;
    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        if (dsu.unionByRank(a, b))
        {
            components--;
        }
        cout << components << " " << dsu.highestRank << "\n";
    }
    return 0;
}