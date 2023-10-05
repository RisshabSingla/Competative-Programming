#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

void dfs(int node, vector<int> &topo, vector<vector<ll>> &graph, vector<bool> &visit)
{
    visit[node] = true;
    for (int i = 0; i < graph[node].size(); i++)
    {
        if (!visit[graph[node][i]])
        {
            dfs(graph[node][i], topo, graph, visit);
        }
    }
    topo.push_back(node);
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            arr[i]--;
        }
        vector<int> costs(n);
        for (int i = 0; i < n; i++)
        {
            cin >> costs[i];
        }

        vector<ll> visited(n, 0);
        ll color = 1;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            // dealing with all the cycles
            if (visited[i] == 0)
            {
                ll node = i;
                while (visited[node] == 0)
                {
                    // coloring the nodes
                    visited[node] = color;
                    node = arr[node];
                }
                if (visited[node] != color)
                {
                    // if node does not have the same color
                    // different cycle
                    color++;
                    continue;
                }
                color++;
                vector<ll> cycle;
                ll itr = node;
                do
                {
                    cycle.push_back(itr);
                    itr = arr[itr];
                } while (itr != node);

                int num_nodes = cycle.size();
                int min_cost = INT_MAX;
                int index = -1;
                for (int i = 0; i < num_nodes; i++)
                {
                    if (costs[cycle[i]] < min_cost)
                    {
                        min_cost = costs[cycle[i]];
                        index = i;
                    }
                }
                // starting from the next node
                index = (index + 1) % num_nodes;
                for (int i = 0; i < num_nodes; i++)
                {
                    // pushing all the cycle nodes into answer
                    ans.push_back(cycle[index]);
                    index = (index + 1) % num_nodes;
                }
            }
        }
        vector<bool> visit(n, false);
        for (auto i : ans)
        {
            visit[i] = true;
        }

        vector<vector<ll>> graph(n);
        for (int i = 0; i < n; i++)
        {
            if (!visit[i] && !visit[arr[i]])
            {
                // both of them are unvisited -> no cycle
                graph[i].push_back(arr[i]);
            }
        }
        vector<int> topo;
        for (int i = 0; i < n; i++)
        {
            if (!visit[i])
            {
                dfs(i, topo, graph, visit);
            }
        }
        reverse(topo.begin(), topo.end());

        for (auto i : topo)
        {
            cout << (i + 1) << " ";
        }
        for (auto i : ans)
        {
            cout << (i + 1) << " ";
        }
        cout << endl;
    }
    return 0;
}
