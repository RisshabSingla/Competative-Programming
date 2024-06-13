#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

string getBinary(ll number, ll n)
{
    string ans = "";
    while (number)
    {
        if (number % 2)
        {
            ans += '1';
        }
        else
        {
            ans += '0';
        }
        number /= 2;
    }
    while (ans.length() != n)
    {
        ans += '0';
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    ll n;
    cin >> n;
    for (ll i = 0; i < (1 << n); i++)
    {
        string str = getBinary(i, n);
        // cout << "String is: " << str << "\n";
        string ans = "";
        ans += str[0];
        for (int i = 1; i < n; i++)
        {
            if (str[i] != str[i - 1])
            {
                ans += '1';
            }
            else
            {
                ans += '0';
            }
        }
        cout << ans << "\n";
    }
    return 0;
}