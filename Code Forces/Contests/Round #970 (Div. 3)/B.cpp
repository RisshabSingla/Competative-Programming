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

bool checkValid(vector<vector<ll>> &arr, ll n)
{
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
            {
                if (arr[i][j] == 0)
                {
                    return false;
                }
            }
            else
            {
                if (arr[i][j] == 1)
                {
                    return false;
                }
            }
        }
    }
    return true;
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
        ll side = sqrt(n);
        if (side * side != n)
        {
            cout << "No\n";
            continue;
        }
        vector<vector<ll>> arr(side, vector<ll>(side, 0));
        for (ll i = 0; i < side; i++)
        {
            for (ll j = 0; j < side; j++)
            {
                arr[i][j] = str[i * side + j] - '0';
            }
        }
        if (checkValid(arr, side))
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}
