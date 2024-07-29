#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

// vector<ll> getPrimes()
// {
//     int n = 2e5 + 3;
//     bool prime[n + 1];
//     memset(prime, true, sizeof(prime));
//     for (int p = 2; p * p <= n; p++)
//     {
//         if (prime[p])
//         {
//             for (int i = p * p; i <= n; i += p)
//             {
//                 prime[i] = false;
//             }
//         }
//     }
//     vector<ll> primes;
//     for (int p = 2; p <= n; p++)
//     {
//         if (prime[p])
//         {
//             primes.push_back(p);
//         }
//     }
//     return primes;
// }

// int greedyColoring(const vector<vector<ll>> &graph)
// {
//     int n = graph.size();
//     vector<int> colors(n, -1);

//     for (int v = 0; v < n; ++v)
//     {
//         unordered_set<int> usedColors;

//         // Check neighbors and mark their colors as used
//         for (int neighbor : graph[v])
//         {
//             if (colors[neighbor] != -1)
//             {
//                 usedColors.insert(colors[neighbor]);
//             }
//         }

//         // Find the smallest available color
//         for (int color = 1;; ++color)
//         {
//             if (usedColors.find(color) == usedColors.end())
//             {
//                 colors[v] = color;
//                 break;
//             }
//         }
//     }

//     // Find the maximum color used (chromatic number)
//     int chromaticNumber = *max_element(colors.begin(), colors.end()) + 1;
//     return chromaticNumber;
// }

// bool isSafe(ll vertex, const vector<vector<ll>> &graph, const vector<ll> &colors, int color)
// {
//     for (ll neighbor : graph[vertex])
//     {
//         if (colors[neighbor] == color)
//         {
//             return false;
//         }
//     }
//     return true;
// }

// bool isPossible(const vector<vector<ll>> &graph, vector<ll> &colors, ll m, ll vertex)
// {
//     if (vertex == graph.size())
//     {
//         return true;
//     }

//     for (int color = 1; color <= m; ++color)
//     {
//         if (isSafe(vertex, graph, colors, color))
//         {
//             colors[vertex] = color;
//             if (isPossible(graph, colors, m, vertex + 1))
//             {
//                 return true;
//             }
//             colors[vertex] = -1;
//         }
//     }

//     return false;
// }

int main()
{
    int cases;
    cin >> cases;
    vector<vector<ll>> ans = {
        {1, 1},
        {2, 1, 2},
        {2, 1, 2, 2},
        {3, 1, 2, 2, 3},
        {3, 1, 2, 2, 3, 3},
        {4, 1, 2, 2, 3, 3, 4},
    };
    // vector<ll> primes = getPrimes();
    while (cases--)
    {
        ll n;
        cin >> n;
        if (n <= 6)
        {
            cout << ans[n - 1][0] << "\n";
            for (ll i = 1; i <= n; i++)
            {
                cout << ans[n - 1][i] << " ";
            }
            cout << "\n";
            continue;
        }
        cout << 4 << "\n";
        for (ll i = 0; i < n; i++)
        {
            cout << ((i % 4) + 1) << " ";
        }
        cout << "\n";
        // vector<vector<ll>> adjList(n);
        // for (auto prime : primes)
        // {
        //     for (ll i = 1; i <= n; i++)
        //     {
        //         ll j = i xor prime;
        //         if (j >= i && j <= n)
        //         {
        //             adjList[i - 1].push_back(j - 1);
        //             adjList[j - 1].push_back(i - 1);
        //         }
        //     }
        // }

        // // int colors = greedyColoring(adjList);

        // // cout << "Chromatic: " << colors << "\n";

        // ll low = 1;
        // ll high = 4;
        // ll ans = 0;
        // vector<ll> colorAssignments;
        // while (low <= high)
        // {
        //     vector<ll> colors(n, -1);
        //     ll mid = low + (high - low) / 2;
        //     if (isPossible(adjList, colors, mid, 0))
        //     {
        //         ans = mid;
        //         high = mid - 1;
        //         colorAssignments = colors;
        //     }
        //     else
        //     {
        //         low = mid + 1;
        //     }
        // }

        // cout << ans << "\n";
        // for (auto i : colorAssignments)
        // {
        //     cout << i << " ";
        // }
        // cout << "\n";
        // for (int i = 0; i < n; i++)
        // {
        //     cout << i << " : ";
        //     for (auto k : adjList[i])
        //     {
        //         cout << k << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
    }
    return 0;
}
