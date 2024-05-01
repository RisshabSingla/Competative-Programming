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
        string str;
        cin >> str;
        ll len = str.length();
        ll index = 0;
        while (str[index] == '0')
        {
            index++;
        }
        ll ans = 0;
        ll count = 0;
        for (ll i = index; i < len; i++)
        {
            if (str[i] == '0')
            {
                ans += (count + 1);
            }
            else
            {
                count++;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
