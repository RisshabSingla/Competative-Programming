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
    int cases;
    cin >> cases;
    while (cases--)
    {
        string str;
        cin >> str;
        vector<vector<ll>> arr(10);
        for (ll i = 0; i < str.length(); i++)
        {
            ll num = str[i] - '0';
            arr[num].push_back(i);
        }
        ll last = -1;
        string ans = "";
        for (ll i = 0; i < 10; i++)
        {
            if (arr[i].size() == 0)
            {
                continue;
            }
            string add = "";
            // reverse(arr[i].begin(), arr[i].end());
            for (auto j : arr[i])
            {
                if (j >= last)
                {
                    char ch = '0' + i;
                    add.push_back(ch);
                }
                else
                {
                    char ch;
                    if (i == 9)
                    {
                        ch = '0' + (i);
                    }
                    else
                    {
                        ch = '0' + (i + 1);
                    }
                    add.push_back(ch);
                }
            }
            sort(add.begin(), add.end());
            last = max(last, arr[i].back());
            ans += add;
            // cout << "Last is: " << last << "\n";
        }
        cout << ans << "\n";
    }
    return 0;
}