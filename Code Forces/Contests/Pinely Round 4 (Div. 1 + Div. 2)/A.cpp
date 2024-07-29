#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

bool isPossible(vector<ll> &arr, ll n, ll index)
{
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        ll maxi = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (i % 2 == 0)
            {
                maxi = max(maxi, arr[i]);
            }
        }
        cout << maxi << "\n";
        // if (n == 1)
        // {
        //     cout << arr[0] << "\n";
        //     continue;
        // }
        // int maxi = 0;
        // for (ll i = 0; i < n; i++)
        // {
        //     if (isPossible(arr, n, i))
        //     {
        //         maxi = max(maxi, arr[i]);
        //     }
        // }
        // cout << maxi << "\n";
    }

    return 0;
}
