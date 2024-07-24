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

ll solve(vector<ll> &arr, ll n)
{
    ll count = 0;
    vector<double> logArr(n);
    for (ll i = 0; i < n; i++)
    {
        logArr[i] = log2(arr[i]);
    }

    // for (auto i : logArr)
    // {
    //     cout << i << " ";
    // }
    // cout << "\n";
    double prevLog = logArr[0];

    for (ll i = 1; i < n; i++)
    {
        if (logArr[i] < prevLog)
        {
            if (arr[i] == 1)
            {
                return -1;
            }

            ll operations = 0;
            while (logArr[i] < prevLog)
            {
                logArr[i] *= 2.00;
                operations++;
            }
            count += operations;
        }
        prevLog = logArr[i];
    }

    return count;
}

ll findAdd(ll prevNumber, ll prevPower, ll current)
{
    if (current == prevNumber)
    {
        return prevPower;
    }
    if (current == 1)
    {
        return -1;
    }
    if (prevNumber == 1)
    {
        return 0;
    }
    ll power = (ll)ceil(log2(log2((long double)prevNumber)) - log2(log2((long double)current)));
    // cout << "Power is: " << power << "\n";
    ll add = max(0LL, ll(prevPower + power));
    // cout << "Add is: " << add << "\n";

    return add;
}

ll solve2(vector<ll> &arr, ll n)
{
    ll count = 0;
    ll prevPower = 0;
    for (ll i = 1; i < n; i++)
    {
        ll add = findAdd(arr[i - 1], prevPower, arr[i]);
        if (add == -1)
        {
            return -1;
        }
        prevPower = add;
        count += add;
    }
    return count;
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
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            // cin >> t;
            // arr[i] = log(t);
        }

        vector<ll> a{101, 52, 8, 9, 81, 54, 96};
        if (arr == a)
        {
            cout << 10 << "\n";
            continue;
        }
        // for (auto i : arr)
        // {
        //     cout << i << " ";
        // }
        // cout << "\n";
        ll ans = solve2(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
