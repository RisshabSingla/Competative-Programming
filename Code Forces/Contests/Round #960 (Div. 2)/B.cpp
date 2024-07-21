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
        ll n, x, y;
        cin >> n >> x >> y;
        x--;
        y--;
        vector<ll> arr(n, 1);
        bool alt = true;
        for (ll i = x + 1; i < n; i++)
        {
            // arr[i] = -1;
            if (alt)
            {
                arr[i] = -1;
            }
            alt = !alt;
        }
        alt = true;
        for (ll i = y - 1; i >= 0; i--)
        {
            if (alt)
            {
                arr[i] = -1;
            }
            alt = !alt;
        }
        for (auto i : arr)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
