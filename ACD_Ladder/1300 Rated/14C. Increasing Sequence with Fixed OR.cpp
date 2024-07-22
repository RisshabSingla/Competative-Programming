#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>

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
        if (n == 1)
        {
            cout << 1 << "\n";
            cout << 1 << "\n";
            continue;
        }
        vector<ll> ans;
        ans.push_back(n);
        // set<ll> ans;
        // ans.insert(n);
        for (int i = 0; i <= log2(n); i++)
        {
            if (n & (1LL << i))
            {
                // cout << "Bit: " << i << " is set\n";
                ll k = n & ~(1LL << (i));
                // cout << "K is: " << k << "\n";
                ans.push_back(k);
                // ans.insert(k);
            }
        }

        reverse(ans.begin(), ans.end());
        if (ans[0] == 0)
        {
            ans.erase(ans.begin());
        }
        // sort(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (auto i : ans)
        {
            if (i == 0)
            {
                continue;
            }
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}