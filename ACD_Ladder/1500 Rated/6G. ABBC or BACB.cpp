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
        string str;
        cin >> str;
        ll n = str.length();
        bool check = false;

        if (str[0] == 'B' || str[n - 1] == 'B')
        {
            check = true;
        }
        for (ll i = 1; i < n; i++)
        {
            if (str[i] == 'B' && str[i - 1] == 'B')
            {
                check = true;
                break;
            }
        }
        if (check)
        {
            ll countA = 0;
            for (char ch : str)
            {
                if (ch == 'A')
                {
                    countA++;
                }
            }
            cout << countA << "\n";
            continue;
        }
        vector<ll> blocks;
        ll count = 0;
        for (ll i = 0; i <= n; i++)
        {
            if (str[i] == 'B' || str[i] == '\0')
            {
                if (count != 0)
                {
                    blocks.push_back(count);
                    count = 0;
                }
            }
            else
            {
                count++;
            }
        }
        sort(blocks.begin(), blocks.end());
        ll ans = 0;
        for (ll i = 1; i < blocks.size(); i++)
        {
            ans += blocks[i];
        }
        cout << ans << "\n";
    }
    return 0;
}