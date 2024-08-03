#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    ll n;
    cin >> n;
    vector<vector<ll>> arr(n, vector<ll>(n, -1));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '.')
            {
                arr[i][j] = 0;
            }
        }
    }
    if (arr[0][0] != -1)
    {
        arr[0][0] = 1;
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (arr[i][j] == 0)
            {
                if (i - 1 >= 0 && arr[i - 1][j] != -1)
                {
                    arr[i][j] += (arr[i - 1][j]);
                    arr[i][j] %= mod;
                }
                if (j - 1 >= 0 && arr[i][j - 1] != -1)
                {
                    arr[i][j] += (arr[i][j - 1]);
                    arr[i][j] %= mod;
                }
            }
        }
    }
    // for (auto i : arr)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << "\n";
    // }

    if (arr[n - 1][n - 1] == -1)
    {
        cout << 0 << "\n";
    }
    else
    {
        cout << arr[n - 1][n - 1];
    }

    return 0;
}