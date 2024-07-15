#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

ll findProduct(ll num)
{
    ll prod = 1;
    while (num)
    {
        prod *= (num % 10);
        num /= 10;
    }
    return prod;
}

ll findProduct(string &str, ll n)
{
    ll prod = 1;
    for (ll i = 0; i < n; i++)
    {
        prod *= (str[i] - '0');
    }
    return prod;
}

int main()
{
    // ll n;
    // cin >> n;
    // if (n < 10)
    // {
    //     cout << n;
    //     return 0;
    // }
    // ll digits = (log(n) / log(10)) + 1;
    // ll ans = pow(9, digits - 1);
    // ll mini = 9;
    // for (ll i = 1; i < digits; i++)
    // {
    //     mini = mini * 10 + 9;
    // }
    // if (mini > n)
    // {
    //     mini = mini / 10;
    // }
    // cout << mini << "\n";
    // for (ll i = n; i >= mini; i--)
    // {
    //     ans = max(ans, findProduct(i));
    // }
    // cout << ans;

    string str;
    cin >> str;
    ll n = str.length();
    if (n == 1)
    {
        cout << str << "\n";
        return 0;
    }

    vector<ll> arr;
    ll curr = 1;
    for (ll i = 0; i < n; i++)
    {
        arr.push_back(str[i] - '0');
        curr *= arr[i];
    }

    ll ans = max(arr[0] - 1, 1LL) * pow(9, n - 1);
    ans = max(ans, curr);
    curr = 1;
    for (ll i = 0; i < n; i++)
    {
        ans = max(ans, ll(curr * (arr[i] - 1) * pow(9, n - i - 1)));
        curr *= arr[i];
    }
    cout << ans;

    return 0;
}