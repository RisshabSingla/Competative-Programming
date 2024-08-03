#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

void updateVal(vector<ll> &tree, ll index, ll num, ll n)
{
    while (index <= n)
    {
        tree[index] += num;
        index = index + (index & -index);
    }
}

ll findSum(vector<ll> &tree, ll index)
{
    ll sum = 0;
    while (index > 0)
    {
        sum += tree[index];
        index = index - (index & -index);
    }
    return sum;
}

int main()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n + 1);

    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    vector<ll> tree(n + 1, 0);

    for (ll i = 1; i <= n; i++)
    {
        updateVal(tree, i, arr[i], n);
    }

    while (q--)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        if (a == 1)
        {
            updateVal(tree, b, c - arr[b], n);
            arr[b] = c;
        }
        else if (a == 2)
        {
            ll tillB = findSum(tree, c);
            ll tillA = findSum(tree, b - 1);
            cout << tillB - tillA << "\n";
        }
    }

    return 0;
}
