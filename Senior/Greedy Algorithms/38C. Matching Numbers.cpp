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
        if (n == 1)
        {
            cout << "YES\n";
            cout << "1 2\n";
            continue;
        }
        if (n % 2 == 0)
        {
            cout << "No\n";
            continue;
        }
        ll start1 = 1;
        ll start2 = n + (n + 1) / 2;
        vector<pll> ans;
        for (ll i = 0; i < n; i++)
        {
            ans.push_back({start1, start2});
            if (start2 == 2 * n)
            {
                start2 = n + 1;
            }
            else
            {
                start2++;
            }
            start1++;
        }
        cout << "YES\n";
        for (auto i : ans)
        {
            cout << i.first << " " << i.second << '\n';
        }
        cout << "\n";
    }
    return 0;
}