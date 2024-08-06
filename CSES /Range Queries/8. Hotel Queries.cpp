#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

class SegmentTree
{
public:
    vector<ll> tree;
    ll n;

    SegmentTree(ll size)
    {
        n = size;
        tree.assign(4 * n, LLONG_MAX);
    }

    ll query(ll leftIndex, ll rightIndex, ll node, ll val)
    {
        if (leftIndex == rightIndex)
        {
            return leftIndex;
        }
        ll mid = leftIndex + (rightIndex - leftIndex) / 2;
        if (tree[2 * node + 1] >= val)
        {
            return query(leftIndex, mid, 2 * node + 1, val);
        }
        return query(mid + 1, rightIndex, 2 * node + 2, val);
    }

    void update(ll leftIndex, ll rightIndex, ll node, ll index, ll val)
    {
        if (leftIndex == rightIndex)
        {
            tree[node] = val;
            return;
        }
        ll mid = leftIndex + (rightIndex - leftIndex) / 2;
        if (index <= mid)
        {
            update(leftIndex, mid, 2 * node + 1, index, val);
        }
        else
        {
            update(mid + 1, rightIndex, 2 * node + 2, index, val);
        }
        if (tree[2 * node + 1] > tree[2 * node + 2])
        {
            tree[node] = tree[2 * node + 1];
        }
        else
        {
            tree[node] = tree[2 * node + 2];
        }
    }

    void buildTree(vector<ll> &arr, ll node, ll leftIndex, ll rightIndex)
    {
        if (leftIndex == rightIndex)
        {
            tree[node] = arr[leftIndex];
            return;
        }
        ll mid = leftIndex + (rightIndex - leftIndex) / 2;
        buildTree(arr, 2 * node + 1, leftIndex, mid);
        buildTree(arr, 2 * node + 2, mid + 1, rightIndex);
        if (tree[2 * node + 1] > tree[2 * node + 2])
        {
            tree[node] = tree[2 * node + 1];
        }
        else
        {
            tree[node] = tree[2 * node + 2];
        }
    }
};

int main()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    SegmentTree tree(n);
    tree.buildTree(arr, 0, 0, n - 1);
    while (q--)
    {
        ll num;
        cin >> num;
        if (tree.tree[0] < num)
        {
            cout << 0 << " ";
            continue;
        }
        ll index = tree.query(0, n - 1, 0, num);
        cout << index + 1 << " ";
        arr[index] -= num;
        tree.update(0, n - 1, 0, index, arr[index]);
    }

    return 0;
}