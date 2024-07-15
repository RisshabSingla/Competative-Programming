#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

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
        string str;
        cin >> str;
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        mp1[str[0] - 'a']++;
        for (int i = 1; i < n; i++)
        {
            mp2[str[i] - 'a']++;
        }
        ll ans = mp1.size() + mp2.size();
        ll size2 = mp2.size();
        for (int i = 1; i < n - 1; i++)
        {
            mp1[str[i] - 'a']++;
            mp2[str[i] - 'a']--;
            if (mp2[str[i] - 'a'] == 0)
            {
                size2--;
            }
            ans = max(ans, (ll)(mp1.size() + size2));
        }
        cout << ans << "\n";
    }
    return 0;
}