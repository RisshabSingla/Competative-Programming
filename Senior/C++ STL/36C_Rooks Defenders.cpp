#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

struct FenwickTree
{
    vector<ll> bit;
    ll n;

public:
    FenwickTree(ll size)
    {
        n = size;
        bit.assign(n + 1, 0);
    }

    void add(ll index, ll val)
    {
        for (++index; index < n; index += (index & -index))
        {
            bit[index] += val;
        }
    }

    ll sum(ll index)
    {
        ll ans = 0;
        for (; index > 0; index -= (index & -index))
        {
            ans += bit[index];
        }
        return ans;
    }

    ll sum(ll left, ll right)
    {
        return sum(right) - sum(left);
    }
};

int main()
{
    ll n, q;
    cin >> n >> q;

    FenwickTree row(n + 1);
    FenwickTree col(n + 1);

    vector<ll> rowCount(n, 0);
    vector<ll> colCount(n, 0);

    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll x, y;
            cin >> x >> y;
            --x, --y;

            if (!rowCount[x])
            {
                row.add(x, 1);
            }

            if (!colCount[y])
            {
                col.add(y, 1);
            }

            ++rowCount[x];
            ++colCount[y];
        }
        else if (t == 2)
        {
            ll x, y;
            cin >> x >> y;
            --x, --y;
            --rowCount[x];
            --colCount[y];

            if (!rowCount[x])
            {
                row.add(x, -1);
            }

            if (!colCount[y])
            {
                col.add(y, -1);
            }
        }
        else
        {
            ll x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            --x1, --y1, --x2, --y2;

            bool xValid = row.sum(x1, x2 + 1) == (x2 - x1 + 1);
            bool yValid = col.sum(y1, y2 + 1) == (y2 - y1 + 1);

            cout << ((xValid || yValid) ? "Yes" : "No") << "\n";
        }
    }

    // map<ll, ll> x;
    // map<ll, ll> y;

    // while (q--)
    // {
    //     ll t;
    //     cin >> t;
    //     if (t == 1)
    //     {
    //         ll a, b;
    //         cin >> a >> b;
    //         x[a]++;
    //         y[b]++;
    //     }
    //     if (t == 2)
    //     {
    //         ll a, b;
    //         cin >> a >> b;
    //         x[a]--;
    //         y[b]--;
    //     }
    //     if (t == 3)
    //     {
    //         ll a, b, c, d;
    //         cin >> a >> b >> c >> d;
    //         bool Xattacked = true;
    //         bool Yattacked = true;
    //         for (ll i = a; i <= c; i++)
    //         {
    //             if (!x.count(i) || x[i] == 0)
    //             {
    //                 Xattacked = false;
    //                 break;
    //             }
    //         }
    //         if (Xattacked)
    //         {
    //             cout << "YES\n";
    //             continue;
    //         }
    //         for (ll i = b; i <= d; i++)
    //         {
    //             if (!y.count(i) || y[i] == 0)
    //             {
    //                 Yattacked = false;
    //                 break;
    //             }
    //         }
    //         if (Yattacked)
    //         {
    //             cout << "YES\n";
    //         }
    //         else
    //         {
    //             cout << "NO\n";
    //         }
    //     }
    // }
    return 0;
}