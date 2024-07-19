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
        string str1;
        string str2;
        cin >> str1 >> str2;

        if (str1 == str2)
        {
            cout << "YES\n";
            continue;
        }

        if (str1[0] == '0' && str2[0] == '1')
        {
            cout << "NO\n";
            continue;
        }
        if (n == 1)
        {
            if (str1[0] == '0' && str2[0] == '1')
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";
            }
            continue;
        }
        bool ans = true;
        bool onePresent = false;
        for (ll i = 0; i < n; i++)
        {
            if (str1[i] == '1')
            {
                onePresent = true;
            }
            if (str1[i] == '0' && str2[i] == '1')
            {
                if (!onePresent)
                {
                    ans = false;
                    break;
                }
            }
        }
        if (ans)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
