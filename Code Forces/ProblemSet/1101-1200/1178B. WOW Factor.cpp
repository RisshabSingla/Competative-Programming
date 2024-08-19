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
    string str;
    cin >> str;

    ll n = str.length();
    vector<ll> front(n + 1, 0);
    vector<ll> back(n + 1, 0);
    for (ll i = 1; i < n; i++)
    {
        front[i] = front[i - 1];
        if (str[i] == 'v' && str[i - 1] == 'v')
        {
            front[i]++;
        }
    }

    for (ll i = n - 2; i >= 0; i--)
    {
        back[i] = back[i + 1];
        if (str[i] == 'v' && str[i + 1] == 'v')
        {
            back[i]++;
        }
    }
    ll ans = 0;
    for (ll i = 1; i < n - 1; i++)
    {
        if (str[i] == 'o')
        {
            ans += (front[i] * back[i]);
        }
    }
    cout << ans << "\n";
    return 0;
}