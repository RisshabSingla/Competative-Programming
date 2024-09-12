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
        string str;
        cin >> str;

        cout << 1 << " ";
        ll prev = 1;
        for (ll i = 1; i < n - 1; i++)
        {
            if (str[i] != str[i - 1])
            {
                prev = i + 1;
            }
            cout << prev << " ";
        }
        cout << "\n";
        // ll zeroCount = 0;
        // ll oneCount = 0;
        // for (ll i = 0; i < n - 1; i++)
        // {
        //     if (str[i] == '0')
        //     {
        //         zeroCount++;
        //     }
        //     else
        //     {
        //         oneCount++;
        //     }
        //     if (zeroCount == 0 || oneCount == 0)
        //     {
        //         cout << 1 << " ";
        //     }
        //     else
        //     {
        //         cout << i + 1 << " ";
        //     }
        // }
        // cout << "\n";
    }
    return 0;
}