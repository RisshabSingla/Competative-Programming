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
        ll n;
        cin >> n;
        vector<ll> arr(n);
        ll sum_odds = 0;
        ll odds = 0;
        ll sum_evens = 0;
        ll evens = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] % 2)
            {
                sum_odds += arr[i];
                odds++;
            }
            else
            {
                sum_evens += arr[i];
                evens++;
            }
        }
        if ((sum_evens == 0 && n % 2) || odds % 2)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
    return 0;
}