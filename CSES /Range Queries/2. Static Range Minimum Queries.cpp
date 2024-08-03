#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    ll log = log2(n) + 1;
    vector<vector<ll>> sparse(n, vector<ll>(log + 1, INT_MAX));
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        sparse[i][0] = arr[i];
    }
    for (ll j = 1; j <= log; j++)
    {
        for (ll i = 0; i + (1 << (j - 1)) < n; i++)
        {
            sparse[i][j] = min(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
        }
    }

    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        ll len = b - a + 1;
        ll window = log2(len);
        cout << min(sparse[a][window], sparse[b - (1 << window) + 1][window]) << "\n";
    }

    return 0;
}