#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#include <unordered_map>

const int mod = 1000000007;

int main()
{
    ll len;
    cin >> len;
    string str;
    cin >> str;
    unordered_map<string, ll> mp;
    string ans = "";
    ll maxi = 0;
    for (ll i = 1; i < len; i++)
    {
        string s = "";
        s += str[i - 1];
        s += str[i];
        mp[s]++;
        if (mp[s] > maxi)
        {
            maxi = mp[s];
            ans = s;
        }
    }
    cout << ans << "\n";

    return 0;
}