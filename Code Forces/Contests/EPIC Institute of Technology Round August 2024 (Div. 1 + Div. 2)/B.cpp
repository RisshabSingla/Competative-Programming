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
        vector<ll> brr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> brr[i];
        }
        if (arr == brr)
        {
            cout << "Bob\n";
            continue;
        }
        reverse(brr.begin(), brr.end());
        if (arr == brr)
        {
            cout << "Bob\n";
            continue;
        }
        cout << "Alice\n";

        // if (arr[0] == brr[0] && arr[n - 1] == brr[n - 1])
        // {
        //     cout << "Bob\n";
        // }
        // else
        // {
        //     cout << "Alice\n";
        // }
    }
    return 0;
}
