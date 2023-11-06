#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<pll> vpl;

const int mod = 1000000007;

void dfs(vector<vector<int>> &adj_list,
         vector<set<int>> &visited, int node, vector<bool> &done)
{
    for (int i = 0; i < adj_list[node].size(); i++)
    {
        if (visited[node].count(adj_list[node][i]) == 0)
        {
            // node is not visited
            visited[node].insert(adj_list[node][i]);
            if (!done[adj_list[node][i]])
            {
                done[adj_list[node][i]] = true;
                dfs(adj_list, visited, adj_list[node][i], done);
            }
            for (auto i : visited[adj_list[node][i]])
            {
                visited[node].insert(i);
            }
        }
    }
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        // ll n;
        // cin >> n;
        // vector<ll> arr1(n);
        // vector<ll> arr2(n);
        // for (ll i = 0; i < n; i++)
        // {
        //     cin >> arr1[i];
        // }
        // for (ll i = 0; i < n; i++)
        // {
        //     cin >> arr2[i];
        // }

        // vector<vector<int>> adj_list(n);

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         if (i == j)
        //         {
        //             continue;
        //         }
        //         if (arr1[i] - arr1[j] >= arr2[i] - arr2[j])
        //         {
        //             adj_list[i].push_back(j);
        //         }
        //     }
        // }
        // // cout << "Done" << endl;
        // vector<set<int>> visited(n);
        // vector<bool> done(n, false);
        // for (int i = 0; i < n; i++)
        // {
        //     visited[i].insert(i);
        //     dfs(adj_list, visited, i, done);
        // }

        // vector<int> ans;
        // for (int i = 0; i < n; i++)
        // {
        //     if (visited[i].size() == n)
        //     {
        //         ans.push_back(i + 1);
        //     }
        // }
        // cout << ans.size() << endl;
        // for (int i = 0; i < ans.size(); i++)
        // {
        //     cout << ans[i] << " ";
        // }
        // cout << endl;

        ll n;
        cin >> n;
        vector<ll> arr1(n);
        vector<ll> arr2(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> arr2[i];
        }

        vpl diff(n);
        for (ll i = 0; i < n; i++)
        {
            diff[i].first = arr1[i] - arr2[i];
            diff[i].second = i;
        }
        sort(diff.begin(), diff.end());
        set<ll> ans;
        for (int i = n - 1; i >= 0; i--)
        {
            if (diff[i].first == diff[n - 1].first)
            {
                ans.insert(diff[i].second + 1);
            }
            else
            {
                break;
            }
        }
        cout << ans.size() << "\n";
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
