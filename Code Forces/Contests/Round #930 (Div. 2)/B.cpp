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

// unordered_map<string, int> mp;
// string ans = "";

// void recur(vector<vector<char>> &arr, int x, int y, string &str, int n)
// {
//     if (ans.length() > 0 && str > ans)
//     {
//         return;
//     }

//     if (str.length() > n + 1)
//     {
//         return;
//     }
//     // if (str.length() > n)
//     // {
//     //     return;
//     // }
//     // cout << "str is: " << str << "\n";
//     if (x == 1 && y == n - 1)
//     {
//         // cout << "Inside\n";
//         if (str.length() == n + 1)
//         {
//             // str.push_back(arr[x][y]);
//             mp[str]++;
//             if (ans.length() > 0 && str < ans)
//             {
//                 // cout << "String is: " << str << "\n";
//                 ans = str;
//             }
//             else
//             {
//                 if (ans.length() == 0)
//                 {
//                     ans = str;
//                 }
//                 // cout << "Changed\n";
//             }
//         }

//         return;
//     }
//     if (x > 1 || y >= n)
//     {
//         return;
//     }

//     if (y + 1 < n)
//     {
//         str.push_back(arr[x][y + 1]);
//         recur(arr, x, y + 1, str, n);
//         str.pop_back();
//     }

//     if (x + 1 < 2)
//     {
//         str.push_back(arr[x + 1][y]);
//         recur(arr, x + 1, y, str, n);
//         str.pop_back();
//     }
// }

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

        string str = "";

        int index = 0;
        int row = 0;
        while (index < n)
        {
            if (row == 0)
            {
                str += str1[index];
                if (index + 1 < n && str2[index] < str1[index + 1])
                {
                    row = 1;
                }
                else if (index + 1 == n)
                {

                    str += str2[index];
                    break;
                }
                else
                {
                    index++;
                }
            }
            else
            {
                str += str2[index];
                index++;
            }
        }

        cout << str << "\n";

        int ans = 1;
        for (int i = 1; i < n; i++)
        {
            if (str1[i] == str2[i - 1])
            {
                ans++;
            }
            else if (str1[i] == '0' && str2[i - 1] == '1')
            {
                ans = 1;
            }
            else
            {
                break;
            }
        }
        cout << ans << "\n";

        // vector<vector<char>> arr(2, vector<char>(n));
        // for (int i = 0; i < 2; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cin >> arr[i][j];
        //     }
        // }

        // for (int i = 0; i <= n; i++)
        // {
        //     ans += '1';
        // }

        // for (auto &i : arr)
        // {
        //     for (auto &j : i)
        //     {
        //         cout << j << " ";
        //     }
        //     cout << '\n';
        // }
        // string str = "";
        // str.push_back(arr[0][0]);
        // recur(arr, 0, 0, str, n);
        // cout << ans << "\n";
        // cout << mp[ans] << "\n";
        // cout << "\n\n";

        // for (auto &i : mp)
        // {
        //     cout << i.first << " : " << i.second << "\n";
        // }
        // mp.clear();
        // ans.clear();
    }
    return 0;
}
