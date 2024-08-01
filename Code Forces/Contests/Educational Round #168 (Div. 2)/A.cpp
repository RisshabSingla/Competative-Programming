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

ll findCost(string &str)
{
    ll count = 2;
    for (ll i = 1; i < str.length(); i++)
    {
        if (str[i] == str[i - 1])
        {
            count++;
        }
        else
        {
            count += 2;
        }
    }
    return count;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        string str;
        cin >> str;
        ll maxi = 0;
        string ans = "";
        ll n = str.length();
        for (int i = 0; i < n; i++)
        {
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                string nStr = str.substr(0, i) + ch + str.substr(i);
                // cout << nStr << "\n";
                ll cost = findCost(nStr);
                if (cost > maxi)
                {
                    maxi = cost;
                    ans = nStr;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
