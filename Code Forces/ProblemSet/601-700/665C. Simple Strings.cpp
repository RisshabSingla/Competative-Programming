#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

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
    string str;
    cin >> str;
    ll n = str.length();

    for (ll i = 1; i < n; ++i)
    {
        if (str[i] == str[i - 1])
        {
            // if the current and the last are the same
            if (str[i] == 'b')
            {
                if (i == n - 1)
                {
                    str[i] = 'a';
                }
                else if (str[i + 1] != 'a')
                {
                    str[i] = 'a';
                }
                else
                {
                    str[i] = 'c';
                }
            }
            else
            {
                if (i == n - 1)
                {
                    str[i] = 'b';
                }
                else if (str[i + 1] != 'b')
                {
                    str[i] = 'b';
                }
                else
                {
                    str[i] = (str[i] == 'a') ? 'c' : 'a';
                }
            }
        }
    }

    cout << str << endl;
}