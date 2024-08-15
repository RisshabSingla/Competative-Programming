#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
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
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        ll m;
        cin >> m;
        while (m--)
        {
            string str;
            cin >> str;
            if (str.length() != n)
            {
                cout << "NO\n";
                continue;
            }
            unordered_map<char, ll> mp1;
            unordered_map<ll, char> mp2;
            bool possible = true;
            for (ll i = 0; i < str.length(); i++)
            {
                if (!mp1.count(str[i]) && !mp2.count(arr[i]))
                {
                    mp1[str[i]] = arr[i];
                    mp2[arr[i]] = str[i];
                }
                if (mp1.count(str[i]) && !mp2.count(arr[i]))
                {
                    possible = false;
                    break;
                }
                if (!mp1.count(str[i]) && mp2.count(arr[i]))
                {
                    possible = false;
                    break;
                }
                if (mp1[str[i]] != arr[i])
                {
                    possible = false;
                    break;
                }
            }
            if (possible)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
    return 0;
}
