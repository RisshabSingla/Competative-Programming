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
        ll n;
        cin >> n;
        string str1;
        cin >> str1;
        string str2;
        cin >> str2;
        if (str1 == str2)
        {
            cout << "YES\n";
            continue;
        }
        int zeroCount = 0;
        int oneCount = 0;
        int j = 0;
        vector<pair<ll, ll>> arr;
        for (int i = 0; i < n; i++)
        {
            if (str1[i] == '1')
            {
                oneCount++;
            }
            else
            {
                zeroCount++;
            }
            if (oneCount == zeroCount)
            {
                arr.push_back({j, i});
                j = i + 1;
            }
        }

        for (auto &i : arr)
        {
            int startIndex = i.first;
            int endIndex = i.second;
            if (str1[startIndex] == str2[startIndex])
            {
                continue;
            }
            for (int k = startIndex; k <= endIndex; k++)
            {
                if (str1[k] == '1')
                {
                    str1[k] = '0';
                }
                else
                {
                    str1[k] = '1';
                }
            }
        }

        bool possible = true;
        for (int i = 0; i < n; i++)
        {
            if (str1[i] != str2[i])
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

        // int zeroCount = 0;
        // int oneCount = 0;
        // bool possible = true;
        // for (int i = 0; i <= n; i++)
        // {
        //     if (str1[i] != str2[i])
        //     {
        //         if (str1[i] == '0')
        //         {
        //             zeroCount++;
        //         }
        //         else
        //         {
        //             oneCount++;
        //         }
        //     }
        //     else
        //     {
        //         if (zeroCount != oneCount)
        //         {
        //             possible = false;
        //             break;
        //         }
        //         zeroCount = 0;
        //         oneCount = 0;
        //     }
        // }
        // if (possible)
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