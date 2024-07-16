#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

// class TreeNode
// {
// public:
//     ll val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode()
//     {
//         val = -1;
//         left = NULL;
//         right = NULL;
//     }
//     TreeNode(ll val)
//     {
//         this->val = val;
//         left = NULL;
//         right = NULL;
//     }
// };

ll dfs(ll node, ll currStep, ll maxSteps, vector<vector<ll>> &dp, vector<vector<ll>> &adjList, ll n, vector<ll> &arr, ll parent)
{
    ll ans = (currStep)*arr[node];
    if (dp[node][currStep] != -1)
    {
        return dp[node][currStep];
    }
    for (auto neighbor : adjList[node])
    {
        if (neighbor == parent)
        {
            continue;
        }
        ll minVal = LLONG_MAX;
        for (ll step = 1; step <= maxSteps + 1; step++)
        {
            if (step == currStep)
            {
                continue;
            }
            minVal = min(minVal, dfs(neighbor, step, maxSteps, dp, adjList, n, arr, node));
        }
        ans += minVal;
    }
    return dp[node][currStep] = ans;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        // ll sum = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            // sum += arr[i];
        }
        if (n == 1)
        {
            cout << arr[0] << "\n";
            continue;
        }

        vector<vector<ll>> adjList(n);
        for (ll i = 0; i < n - 1; i++)
        {
            ll a, b;
            cin >> a >> b;
            a--;
            b--;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }

        ll reqSteps = ceil(log2(n));
        vector<vector<ll>> dp(n + 1, vector<ll>(reqSteps + 2, -1));

        ll ans = LLONG_MAX;
        for (ll i = 1; i <= reqSteps + 1; i++)
        {
            ans = min(ans, dfs(0, i, reqSteps, dp, adjList, n, arr, -1));
        }
        cout << ans << "\n";

        // map<ll, TreeNode *> mp;
        // map<ll, ll> child;
        // for (int i = 0; i < n - 1; i++)
        // {
        //     ll a, b;
        //     cin >> a >> b;
        //     a--;
        //     b--;
        //     TreeNode *node1 = NULL;
        //     TreeNode *node2 = NULL;
        //     if (mp.count(a))
        //     {
        //         node1 = mp[a];
        //     }
        //     if (mp.count(b))
        //     {
        //         node1 = mp[b];
        //     }

        //     if (!node1)
        //     {
        //         node1 = new TreeNode(arr[a]);
        //         mp[a] = node1;
        //     }
        //     if (!node2)
        //     {
        //         node2 = new TreeNode(arr[b]);
        //         mp[b] = node2;
        //     }
        //     if (node1->left == NULL)
        //     {
        //         node1->left = node2;
        //         child[b]++;
        //     }
        //     else if (node1->right == NULL)
        //     {
        //         node1->right = node2;
        //         child[b]++;
        //     }
        //     else if (node2->left == NULL)
        //     {
        //         node2->left = node1;
        //         child[a]++;
        //     }
        //     else
        //     {
        //         node2->right = node1;
        //         child[a]++;
        //     }
        // }

        // int rt = 0;
        // for (auto i : child)
        // {
        //     cout << i.first << " " << i.second << "\n";
        //     if (i.second == 0)
        //     {
        //         rt = i.first;
        //         break;
        //     }
        // }
        // TreeNode *root = mp[0];
        // cout << "Root val is: " << root->val << "\n";

        // queue<TreeNode *> q;
        // q.push(root);
        // q.push(NULL);
        // int index = 0;
        // vector<ll> count(2, 0);
        // while (!q.empty())
        // {
        //     TreeNode *front = q.front();
        //     q.pop();
        //     if (front == NULL)
        //     {
        //         if (!q.empty())
        //         {
        //             q.push(NULL);
        //         }
        //         index++;
        //         index %= 2;
        //         continue;
        //     }
        //     count[index] += front->val;
        //     // cout << front->val << " ";
        //     if (front->left)
        //     {
        //         q.push(front->left);
        //     }
        //     if (front->right)
        //     {
        //         q.push(front->right);
        //     }
        // }
        // ll ans = sum + min(count[0], count[1]);
        // cout << ans << "\n";
    }
    return 0;
}