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
        string str;
        cin >> str;
        vector<bool> changed(n, false);
        vector<ll> arr;
        ll ans = 0;
        for (ll i = 1; i <= n; i++)
        {
            if (str[i - 1] == '0')
            {
                ll j = 1;
                while (((i * j) - 1) < n &&
                       (str[((i * j) - 1)] == '0'))
                {
                    if (!changed[((i * j) - 1)])
                    {
                        ans += i;
                    }
                    changed[((i * j) - 1)] = true;
                    j++;
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}