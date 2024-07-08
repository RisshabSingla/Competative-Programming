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
        vector<ll> arr(n);
        for (ll i = 1; i <= n; i++)
        {
            arr[i - 1] = i;
        }

        for (ll k = 2; k <= n; k++)
        {
            for (ll j = 1; j * k <= n; j++)
            {
                arr[k * j - 1] = k * j;
            }
        }
        for (auto i : arr)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
