#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

ll query(ll qLeft, ll qRight, ll leftIndex, ll rightIndex, ll node, vector<ll> &tree)
{
    if (qLeft > rightIndex || qRight < leftIndex)
    {
        return LLONG_MAX;
    }

    if (leftIndex >= qLeft && rightIndex <= qRight)
    {
        return tree[node];
    }

    ll mid = leftIndex + (rightIndex - leftIndex) / 2;
    ll leftAns = query(qLeft, qRight, leftIndex, mid, 2 * node + 1, tree);
    ll rightAns = query(qLeft, qRight, mid + 1, rightIndex, 2 * node + 2, tree);
    return min(leftAns, rightAns);
}

void update(ll index, ll val, ll leftIndex, ll rightIndex, ll node, vector<ll> &tree)
{
    if (index > rightIndex || index < leftIndex)
    {
        return;
    }
    if (leftIndex == rightIndex)
    {
        if (leftIndex == index)
        {
            tree[node] = val;
        }
        return;
    }
    ll mid = leftIndex + (rightIndex - leftIndex) / 2;
    update(index, val, leftIndex, mid, 2 * node + 1, tree);
    update(index, val, mid + 1, rightIndex, 2 * node + 2, tree);
    tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
}

void buildTree(vector<ll> &tree, vector<ll> &arr, ll node, ll leftIndex, ll rightIndex)
{
    if (leftIndex == rightIndex)
    {
        tree[node] = arr[leftIndex];
        return;
    }
    ll mid = leftIndex + (rightIndex - leftIndex) / 2;
    buildTree(tree, arr, 2 * node + 1, leftIndex, mid);
    buildTree(tree, arr, 2 * node + 2, mid + 1, rightIndex);
    tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
}

int main()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<ll> tree(4 * n, LLONG_MAX);
    buildTree(tree, arr, 0, 0, n - 1);
    // for (auto i : tree)
    // {
    //     cout << i << " ";
    // }

    while (q--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            update(b - 1, c, 0, n - 1, 0, tree);
        }
        else
        {
            cout << query(b - 1, c - 1, 0, n - 1, 0, tree) << "\n";
        }
    }
    return 0;
}