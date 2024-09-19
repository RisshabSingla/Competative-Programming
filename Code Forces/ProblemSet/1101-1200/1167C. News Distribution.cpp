#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<pll> vpl;
typedef vector<int> vi;

const int mod = 1000000007;

class DisjointSet
{
public:
    vector<ll> rank, parent, size;

    DisjointSet(ll n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (ll i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    ll findUPar(ll node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(ll u, ll v)
    {
        ll ulp_u = findUPar(u);
        ll ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(ll u, ll v)
    {
        ll ulp_u = findUPar(u);
        ll ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main()
{
    ll n, m;
    cin >> n >> m;
    DisjointSet ds(n);
    for (ll i = 0; i < m; i++)
    {
        ll t;
        cin >> t;
        vector<ll> arr(t);
        for (ll j = 0; j < t; j++)
        {
            cin >> arr[j];
        }
        for (ll j = 1; j < t; j++)
        {
            ds.unionBySize(arr[j - 1], arr[j]);
        }
    }

    // vector<ll> ans(n + 1, -1);
    // vector<bool> visited(n + 1, false);
    // for (ll i = 1; i <= n; i++)
    // {
    //     if (!visited[i])
    //     {
    //         ll count = 0;
    //         ll node = i;
    //         while (ds.parent[node] != node)
    //         {
    //             node = ds.parent[node];
    //             count++;
    //         }
    //     }
    // }

    vector<ll> ans(n + 1, 1);
    for (ll i = 1; i <= n; i++)
    {
        ll parent = ds.findUPar(i);
        ans[i] = ds.size[parent];
    }

    for (ll i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}