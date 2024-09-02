#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<pll> vpl;
typedef vector<int> vi;

const int mod = 1000000007;

void dfs(vector<vector<ll>> &adjList, ll n, ll current, ll currColor, vector<ll> &colors)
{
    if (colors[current] != -1)
    {
        return;
    }
    colors[current] = currColor;
    for (auto neighbor : adjList[current])
    {
        dfs(adjList, n, neighbor, (currColor + 1) % 2, colors);
    }
}

int main()
{
    ll n;
    cin >> n;
    vector<vector<ll>> adjList(n);
    for (ll i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        adjList[a - 1].push_back(b - 1);
        adjList[b - 1].push_back(a - 1);
    }
    vector<ll> color(n, -1);
    dfs(adjList, n, 0, 1, color);

    ll count1 = 0;
    ll count2 = 0;
    for (ll i = 0; i < n; i++)
    {
        if (color[i] == 1)
        {
            count1++;
        }
        else
        {
            count2++;
        }
    }
    cout << count1 * count2 - (n - 1) << "\n";

    // set<pair<ll, ll>> st;
    // set<ll> st1;
    // set<ll> st2;
    // for (ll i = 0; i < n - 1; i++)
    // {
    //     ll a, b;
    //     cin >> a >> b;
    //     st.insert({a, b});
    //     if (st1.count(a))
    //     {
    //         st2.insert(b);
    //     }
    //     else if (st2.count(a))
    //     {
    //         st1.insert(b);
    //     }
    //     else
    //     {
    //         st1.insert(a);
    //         st2.insert(b);
    //     }
    // }
    // ll count = 0;
    // for (auto start : st1)
    // {
    //     for (auto end : st2)
    //     {
    //         if (!st.count({start, end}) && !st.count({end, start}))
    //         {
    //             count++;
    //             st.insert({start, end});
    //         }
    //     }
    // }
    // cout << count << "\n";

    return 0;
}