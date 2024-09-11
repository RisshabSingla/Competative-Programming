#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

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

        ll ans = 1;
        for (ll i = 1; i < 2 * n; i++)
        {
            if (str[i] == '(' && str[i - 1] == '(')
            {
                ans++;
            }
        }
        cout << ans << '\n';
        // vector<pair<ll, ll>> arr;
        // vector<ll> indexes;
        // stack<ll> stk;
        // indexes.push_back(-1);
        // for (ll i = 0; i < 2 * n; i++)
        // {
        //     if (str[i] == ')')
        //     {
        //         ll top = stk.top();
        //         stk.pop();
        //         if (stk.empty())
        //         {
        //             indexes.push_back(i);
        //         }
        //         else
        //         {
        //             arr.push_back({top, i});
        //         }
        //     }
        //     else
        //     {
        //         stk.push(i);
        //     }
        // }
        // ll ans = arr.size();
        // ll m = indexes.size();
        // cout << "ans is: " << ans << "\n";
        // cout << "M is: " << m << "\n";
        // if (m != 0)
        // {
        //     ans++;
        // }
        // cout << ans << "\n";

        // cout << m << " " << arr.size() << "\n";
        // for (ll i = 0; i < m; i++)
        // {
        //     for (ll j = i + 1; j < m; j++)
        //     {
        //         arr.push_back({indexes[i] + 1, indexes[j]});
        //     }
        // }
        // cout << m << " " << arr.size() << "\n\n";

        // for (auto i : arr)
        // {
        //     cout << i.first << " " << i.second << "\n";
        // }
        // cout << "\n";
    }
    return 0;
}