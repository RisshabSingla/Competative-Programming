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
    ll query(ll qLeft, ll qRight, ll leftIndex, ll rightIndex, ll node)
    {
        if (qLeft > rightIndex || qRight < leftIndex)
        {
            return 0;
        }

        if (leftIndex >= qLeft && rightIndex <= qRight)
        {
            return tree[node];
        }

        ll mid = leftIndex + (rightIndex - leftIndex) / 2;
        ll leftAns = query(qLeft, qRight, leftIndex, mid, 2 * node + 1);
        ll rightAns = query(qLeft, qRight, mid + 1, rightIndex, 2 * node + 2);
        return leftAns xor rightAns;
    }

    void update(ll index, ll val, ll leftIndex, ll rightIndex, ll node)
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
        update(index, val, leftIndex, mid, 2 * node + 1);
        update(index, val, mid + 1, rightIndex, 2 * node + 2);
        tree[node] = tree[2 * node + 1] xor tree[2 * node + 2];
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
        tree[node] = tree[2 * node + 1] xor tree[2 * node + 2];
    }
};

int main()
{
    ll n, q;
    cin >> n >> q;
    SegmentTree tree(n);
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    tree.buildTree(arr, 0, 0, n - 1);
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        cout << tree.query(a - 1, b - 1, 0, n - 1, 0) << "\n";
    }

    return 0;
}