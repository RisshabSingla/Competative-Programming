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
    while (cases--)
    {
        string str;
        cin >> str;
        ll n = str.length();
        if (n < 3)
        {
            cout << "NO\n";
            continue;
        }
        if (str[0] != '1' || str[1] != '0' || str[2] == '0')
        {
            cout << "NO\n";
            continue;
        }
        if (n == 3 && str[2] < '2')
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
    return 0;
}
