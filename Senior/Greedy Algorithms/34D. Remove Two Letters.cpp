#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

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
        ll ans = n - 1;
        for (ll i = 1; i < n - 1; i++)
        {
            if (str[i - 1] == str[i + 1])
            {
                ans--;
            }
        }
        cout << ans << "\n";
        // set<string> ans;
        // for (ll i = 0; i <= n - 2; i++)
        // {
        //     string s1 = str.substr(i + 2);
        //     string s2 = "";
        //     if (i > 0)
        //     {
        //         s2 = str.substr(0, i);
        //     }
        //     string s = s2 + s1;
        //     // cout << "String is: " << s << "\n";
        //     ans.insert(s);
        // }
        // cout << ans.size() << "\n";
    }
    return 0;
}