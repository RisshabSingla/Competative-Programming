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
        vector<vector<ll>> arr(n, vector<ll>(n, 0));
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                char ch;
                cin >> ch;
                arr[i][j] = ch - '0';
                // cin >> arr[i][j];
            }
        }
        ll count = 0;
        for (ll i = 0; i <= n / 2; i++)
        {
            for (ll j = i; j < (n - i - 1); j++)
            {
                ll x = i;
                ll y = j;
                ll one = 0;
                ll zero = 0;
                for (ll k = 0; k < 4; k++)
                {
                    ll nx = y;
                    ll ny = n - x - 1;
                    // cout << nx << " " << ny << '\n';
                    if (arr[nx][ny] == 0)
                    {
                        zero++;
                    }
                    else
                    {
                        one++;
                    }
                    x = nx;
                    y = ny;
                }
                // cout << "\n";
                // cout << "Zero: " << zero << " one: " << one << "\n";
                ll opr = min(one, zero);
                count += opr;
            }
        }
        cout << count << "\n";
        // cout << "\n";
        // cout << "\n";
    }
    return 0;
}