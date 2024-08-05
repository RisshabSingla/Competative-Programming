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
    vector<ll> unPropogatedUpdate;
    vector<bool> isLazy;
    ll n;
    SegmentTree(ll size)
    {
        n = size;
        tree.assign(4 * n, LLONG_MAX);
        unPropogatedUpdate.assign(4 * n, 0);
        isLazy.assign(4 * n, false);
    }
    void apply(ll node, ll leftIndex, ll rightIndex, ll val)
    {
        if (leftIndex != rightIndex)
        {
            isLazy[node] = true;
            unPropogatedUpdate[node] += val;
        }
        tree[node] += (rightIndex - leftIndex + 1) * val;
    }

    void pushDownLaziness(ll node, ll leftIndex, ll rightIndex)
    {
        if (!isLazy[node])
        {
            return;
        }
        isLazy[node] = false;
        ll mid = leftIndex + (rightIndex - leftIndex) / 2;
        apply(2 * node + 1, leftIndex, mid, unPropogatedUpdate[node]);
        apply(2 * node + 2, mid + 1, rightIndex, unPropogatedUpdate[node]);
        unPropogatedUpdate[node] = 0;
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

        pushDownLaziness(node, leftIndex, rightIndex);
        ll mid = leftIndex + (rightIndex - leftIndex) / 2;
        ll leftAns = query(qLeft, qRight, leftIndex, mid, 2 * node + 1);
        ll rightAns = query(qLeft, qRight, mid + 1, rightIndex, 2 * node + 2);
        return leftAns xor rightAns;
    }

    void update(ll left, ll right, ll val, ll leftIndex, ll rightIndex, ll node)
    {
        if (left > rightIndex || right < leftIndex)
        {
            return;
        }
        if (leftIndex >= left && rightIndex <= right)
        {
            apply(node, leftIndex, rightIndex, val);
            return;
        }
        pushDownLaziness(node, leftIndex, rightIndex);
        ll mid = leftIndex + (rightIndex - leftIndex) / 2;
        update(left, right, val, leftIndex, mid, 2 * node + 1);
        update(left, right, val, mid + 1, rightIndex, 2 * node + 2);
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
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    SegmentTree tree(n);
    tree.buildTree(arr, 0, 0, n - 1);
    while (q--)
    {
        ll a;
        cin >> a;
        if (a == 1)
        {
            ll b, c, d;
            cin >> b >> c >> d;
            b--;
            c--;
            tree.update(b, c, d, 0, n - 1, 0);
        }
        else
        {
            ll b;
            cin >> b;
            b--;
            cout << tree.query(b, b, 0, n - 1, 0) << "\n";
        }
    }
    return 0;
}