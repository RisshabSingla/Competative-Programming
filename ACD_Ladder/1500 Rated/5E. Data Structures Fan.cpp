#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<pll> vpl;
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
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        string str;
        cin >> str;
        ll xorZero = 0;
        ll xorOne = 0;
        vector<ll> pref(n + 1, 0);
        for (ll i = 1; i <= n; i++)
        {
            pref[i] = pref[i - 1] xor arr[i - 1];
            if (str[i - 1] == '0')
            {
                xorZero = xorZero xor arr[i - 1];
            }
            else
            {
                xorOne = xorOne xor arr[i - 1];
            }
        }
        ll q;
        cin >> q;
        while (q--)
        {
            ll type;
            cin >> type;
            if (type == 1)
            {
                ll a, b;
                cin >> a >> b;
                ll between = pref[b] xor pref[a - 1];
                xorZero = xorZero xor between;
                xorOne = xorOne xor between;
            }
            else
            {
                ll num;
                cin >> num;
                if (num == 0)
                {
                    cout << xorZero << " ";
                }
                else
                {
                    cout << xorOne << " ";
                }
            }
        }
        cout << "\n";
    }
    return 0;
}