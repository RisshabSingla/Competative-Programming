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
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n, k;
        cin >> n >> k;
        vector<vector<ll>> arr(n, vector<ll>(n, 0));
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }
        if (n == 1)
        {
            cout << "YES\n";
            continue;
        }
        ll req = 0;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                if (arr[i][j] != arr[n - 1 - i][n - 1 - j])
                {
                    req++;
                }
            }
        }

        req /= 2;

        // if (n % 2)
        // {
        //     for (ll j = 0; j < n / 2; j++)
        //     {
        //         if (arr[n / 2][j] != arr[n / 2][n - 1 - j])
        //         {
        //             req++;
        //         }
        //     }
        // }
        // cout << req << "\n";

        if (req > k)
        {
            cout << "NO\n";
            continue;
        }
        ll rem = k - req;
        if (n % 2)
        {
            cout << "YES\n";
        }
        else if (rem % 2 == 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}