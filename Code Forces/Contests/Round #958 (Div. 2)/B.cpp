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
        string str;
        cin >> str;
        if (n == 1)
        {
            if (str == "1")
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
            continue;
        }

        int ones = 0;
        int zeros = 0;
        if (str[0] == '0')
        {
            zeros++;
        }
        else
        {
            ones++;
        }

        for (int i = 1; i < n; i++)
        {
            if (str[i] == str[i - 1] && str[i - 1] == '0')
            {
                continue;
            }
            if (str[i] == '1')
            {
                ones++;
            }
            else
            {
                zeros++;
            }
        }
        if (ones > zeros)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }

        // int zeros = 0;
        // int ones = 0;
        // int firstIndex = INT_MAX;
        // int lastIndex = -1;
        // vector<int> indexes;
        // for (int i = 0; i < n; i++)
        // {
        //     if (str[i] == '1')
        //     {
        //         firstIndex = min(firstIndex, i);
        //         lastIndex = max(lastIndex, i);
        //         ones++;
        //         indexes.push_back(i);
        //     }
        //     else
        //     {
        //         zeros++;
        //     }
        // }
        // if (ones < 2)
        // {
        //     cout << "NO\n";
        //     continue;
        // }
        // // for (auto i : indexes)
        // // {
        // //     cout << i << " ";
        // // }
        // // cout << "\n";
        // int pairs = 0;
        // for (int i = 1; i < indexes.size(); i++)
        // {
        //     if (indexes[i] - indexes[i - 1] == 1)
        //     {
        //         pairs++;
        //     }
        // }
        // // cout << "Pairs: " << pairs << "\n";
        // if (pairs > 1)
        // {
        //     cout << "YES\n";
        // }
        // else if (firstIndex == 0 && lastIndex == n - 1)
        // {
        //     cout << "YES\n";
        // }
        // else
        // {
        //     cout << "NO\n";
        // }
    }
    return 0;
}
