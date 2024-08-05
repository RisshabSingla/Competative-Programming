#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

ll solve(string &str, ll start, ll end, char deleted)
{
    if (start > end)
    {
        return 0;
    }
    // cout << "Start: " << start << " End: " << end << " del:" << deleted << "\n";
    if (str[start] != str[end])
    {
        if (deleted == 0)
        {
            ll a = solve(str, start + 1, end, str[start]);
            ll b = solve(str, start, end - 1, str[end]);
            return min(min(a, b) + 1, ll(INT_MAX));
        }

        if (str[start] == deleted)
        {
            ll a = solve(str, start + 1, end, deleted);
            return min(a + 1, ll(INT_MAX));
        }
        if (str[end] == deleted)
        {
            ll a = solve(str, start, end - 1, deleted);
            return min(a + 1, ll(INT_MAX));
        }
        // cout << "return max\n";
        return INT_MAX;
    }
    return solve(str, start + 1, end - 1, deleted);
}

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
        ll ans = solve(str, 0, n - 1, 0);
        if (ans == INT_MAX)
        {
            ans = -1;
        }
        cout << ans << "\n";
    }
    return 0;
}