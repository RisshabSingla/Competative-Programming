#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

ll dp[21][21][21][21];

ll findAns(string &str1, string &str2, ll start1, ll start2, ll end1, ll end2)
{
    if (start1 > end1)
    {
        return (end2 - start2 + 1);
    }
    if (start2 > end2)
    {
        return (end1 - start1 + 1);
    }
    if ((end1 - start1) == (end2 - start2) && str1[start1] == str2[start2])
    {
        ll length = end1 - start1 + 1;
        ll i = 0;
        for (i = 0; i < length; i++)
        {
            if (str1[start1 + i] != str2[start2 + i])
            {
                break;
            }
        }
        if (i == length)
        {
            dp[start1][start2][end1][end2] = 0;
            return 0;
        }
    }
    if (dp[start1][start2][end1][end2] != -1)
    {
        return dp[start1][start2][end1][end2];
    }

    ll a1 = findAns(str1, str2, start1 + 1, start2, end1, end2) + 1;
    ll a3 = findAns(str1, str2, start1, start2, end1 - 1, end2) + 1;
    ll a2 = findAns(str1, str2, start1, start2 + 1, end1, end2) + 1;
    ll a4 = findAns(str1, str2, start1, start2, end1, end2 - 1) + 1;
    return dp[start1][start2][end1][end2] = min({a1, a2, a3, a4});
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        memset(dp, -1, sizeof(dp));
        string str1;
        string str2;
        cin >> str1 >> str2;
        if (str1 == str2)
        {
            cout << 0 << "\n";
            continue;
        }
        cout << findAns(str1, str2, 0, 0, str1.length() - 1, str2.length() - 1) << "\n";
    }
    return 0;
}