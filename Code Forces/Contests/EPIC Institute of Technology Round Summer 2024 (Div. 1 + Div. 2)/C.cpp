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

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        ll maxi = -1;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            maxi = max(maxi, arr[i] + i);
        }
        // ll index = 0;
        // for (ll i = 0; i < n; i++)
        // {
        //     if (arr[i] == maxi)
        //     {
        //         index = i;
        //     }
        // }
        // for (ll i = 0; i < n; i++)
        // {
        //     maxi = max(maxi, arr[i] + i);
        // }
        cout << maxi << "\n";
        // cout << maxi + index << "\n";
    }
    return 0;
}
