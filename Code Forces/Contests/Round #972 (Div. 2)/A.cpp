#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    int cases;
    cin >> cases;
    string vowels = "aeiou";
    while (cases--)
    {
        ll n;
        cin >> n;
        string ans = "";
        if (n <= 5)
        {
            for (ll i = 0; i < n; i++)
            {
                ans.push_back(vowels[i % 5]);
            }
            cout << ans << "\n";
            continue;
        }
        ll count = n / 5;
        ll extra = n % 5;
        for (ll i = 0; i < extra; i++)
        {
            for (ll j = 0; j < count + 1; j++)
            {
                ans.push_back(vowels[i]);
            }
        }
        for (ll i = extra; i < 5; i++)
        {
            for (ll j = 0; j < count; j++)
            {
                ans.push_back(vowels[i]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
