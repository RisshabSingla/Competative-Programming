#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, q;
    cin >> n >> q;
    // vector<ll> arr(n);
    // for (ll i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    //     arr[i]--;
    // }

    ll maxi = 30;

    vector<vector<ll>> table(maxi + 1, vector<ll>(n, -1));
    for (ll i = 0; i < n; i++)
    {
        cin >> table[0][i];
        table[0][i]--;
    }

    for (ll i = 1; i <= maxi; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            table[i][j] = table[i - 1][table[i - 1][j]];
        }
    }

    while (q--)
    {
        ll node, k;
        cin >> node >> k;
        node--;
        ll ans = node;
        for (ll i = 0; i <= maxi; i++)
        {
            if (k & (1 << i))
            {
                ans = table[i][ans];
            }
        }
        cout << ans + 1 << "\n";
    }

    // Rows -> n Cols -> Binary
    // ll maxi = 30;

    // vector<vector<ll>> table(n, vector<ll>(maxi + 1, -1));
    // for (ll i = 0; i < n; i++)
    // {
    //     cin >> table[i][0];
    //     table[i][0]--;
    // }

    // for (ll i = 1; i <= maxi; i++)
    // {
    //     for (ll j = 0; j < n; j++)
    //     {
    //         table[j][i] = table[table[j][i - 1]][i - 1];
    //     }
    // }

    // while (q--)
    // {
    //     ll node, k;
    //     cin >> node >> k;
    //     node--;
    //     ll ans = node;
    //     for (ll i = 0; i <= maxi; i++)
    //     {
    //         if (k & (1 << i))
    //         {
    //             ans = table[ans][i];
    //         }
    //     }
    //     cout << ans + 1 << "\n";
    // }

    // while (q--)
    // {
    //     ll node, k;
    //     cin >> node >> k;
    //     node--;
    //     while (k--)
    //     {
    //         node = arr[node];
    //     }
    //     cout << node + 1 << "\n";
    // }
    return 0;
}