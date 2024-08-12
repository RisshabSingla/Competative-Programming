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

// bool isPossible(vector<ll> &perm, ll n, vector<vector<ll>> &tree, ll &index, ll node)
// {
//     if (tree[node].size() == 0)
//     {
//         // cout << "Node: " << node << " zero 0\n";
//         return true;
//     }
//     if (index + 1 >= n)
//     {
//         return true;
//     }
//     ll child1 = tree[node][0];
//     ll child2 = tree[node][1];
//     bool ans = true;
//     bool left = false;
//     bool right = false;
//     if (perm[index + 1] == child1 + 1)
//     {
//         left = true;
//     }
//     if (perm[index + 1] == child2 + 1)
//     {
//         right = true;
//     }
//     if (!left && !right)
//     {
//         return false;
//     }
//     if (left)
//     {
//         // cout << "Left\n";
//         index++;
//         if (!isPossible(perm, n, tree, index, child1))
//         {
//             return false;
//         }
//     }
//     if (right)
//     {
//         // cout << "Right\n";
//         index++;
//         if (!isPossible(perm, n, tree, index, child2))
//         {
//             return false;
//         }
//     }

//     if (left)
//     {
//         // cout << "Other Right\n";
//         index++;
//         if (!isPossible(perm, n, tree, index, child2))
//         {
//             return false;
//         }
//     }

//     if (right)
//     {
//         // cout << "Other Left\n";
//         index++;
//         if (!isPossible(perm, n, tree, index, child1))
//         {
//             return false;
//         }
//     }
//     return true;

//     // if (perm[index + 1] == child1 + 1)
//     // {
//     //     index++;
//     //     cout << "Child One\n";
//     //     ans = ans & isPossible(perm, n, tree, index, child1);
//     // }
//     // if (perm[index + 1] == child2 + 1)
//     // {
//     //     cout << "Child Two\n";
//     //     index++;
//     //     ans = ans & isPossible(perm, n, tree, index, child2);
//     // }
//     // if (perm[index + 1] == child2 + 1)
//     // {
//     //     cout << "Child Two\n";
//     //     index++;
//     //     ans = ans & isPossible(perm, n, tree, index, child2);
//     // }
//     // if (perm[index + 1] == child1 + 1)
//     // {
//     //     index++;
//     //     cout << "Child One\n";
//     //     ans = ans & isPossible(perm, n, tree, index, child1);
//     // }

//     // return ans;
// }

bool isPossible(unordered_map<ll, ll> &parents, ll index, ll level, vector<ll> &perm, ll CP)
{
    if (level <= 0)
    {
        return true;
    }
    ll ind1 = index + 1;
    ll ind2 = ind1 + pow(2, level) - 1;
    // cout << "index1: " << ind1 << " index2: " << ind2 << "\n";
    // for (auto i : perm)
    // {
    //     cout << i << " ";
    // }
    // cout << "\n";
    // cout << parents[perm[ind1]] << " " << parents[perm[ind2]] << "\n";
    if (parents[perm[ind1]] != parents[perm[ind2]])
    {
        return false;
    }
    if (parents[perm[ind1]] != CP)
    {
        return false;
    }
    return isPossible(parents, ind1, level - 1, perm, perm[ind1]) && isPossible(parents, ind2, level - 1, perm, perm[ind2]);
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n, q;
        cin >> n >> q;
        ll levels = log2(n + 1) - 1;

        // vector<vector<ll>> tree(levels + 1);
        // vector<ll> parents(n - 1);
        unordered_map<ll, ll> mp;
        for (ll i = 2; i <= n; i++)
        {
            ll t;
            cin >> t;
            mp[i] = t;
            // tree[t - 1].push_back(i);
        }
        vector<ll> perm(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> perm[i];
        }
        while (q--)
        {
            ll a, b;
            cin >> a >> b;
            a--;
            b--;
            swap(perm[a], perm[b]);
            ll index = 0;
            if (perm[0] != 1)
            {
                cout << "NO\n";
            }
            else if (isPossible(mp, 0, levels, perm, 1))
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }

            // else if (isPossible(perm, n, tree, index, 0))
            // {
            //     cout << "YES\n";
            // }
            // else
            // {
            //     cout << "NO\n";
            // }
            // cout << "index: " << index << "\n";
        }
    }
    return 0;
}
