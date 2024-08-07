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
        string str1;
        cin >> str1;
        string str2;
        cin >> str2;
        ll n = str1.length();
        ll index = 0;
        bool possible = true;
        for (ll i = 0; i < str2.length(); i++)
        {
            if (str1[index] != str2[i])
            {
                while (index < n && str1[index] != str2[i])
                {
                    if (str1[index] == '?')
                    {
                        str1[index] = str2[i];
                        break;
                    }
                    index++;
                }
                if (index < n && str1[index] == str2[i])
                {
                    index++;
                }
                else
                {
                    possible = false;
                    break;
                }
            }
            else
            {
                index++;
            }
        }

        while (index < n)
        {
            if (str1[index] == '?')
            {
                str1[index] = 'a';
            }
            index++;
        }
        if (possible)
        {
            cout << "Yes\n";
            cout << str1 << "\n";
        }
        else
        {
            cout << "NO\n";
        }

        // vector<vector<ll>> pos(26);
        // vector<ll> question;
        // for (ll i = 0; i < str1.length(); i++)
        // {
        //     if (str1[i] == '?')
        //     {
        //         question.push_back(i);
        //     }
        //     else
        //     {
        //         pos[str1[i] - 'a'].push_back(i);
        //     }
        // }
        // for (auto i : question)
        // {
        //     cout << i << ' ';
        // }
        // cout << "\n";
        // ll prev = -1;
        // bool possible = true;
        // for (ll i = 0; i < str2.length(); i++)
        // {
        //     int ch = str2[i] - 'a';
        //     auto itr = upper_bound(pos[ch].begin(), pos[ch].end(), prev);
        //     if (itr == pos[ch].end())
        //     {
        //         cout << "Itr is end\n";
        //         auto itr2 = lower_bound(question.begin(), question.end(), prev);
        //         if (itr2 == question.end())
        //         {
        //             cout << "Itr2 is end\n";
        //             possible = false;
        //             break;
        //         }
        //         prev = *itr2;
        //         cout << "Prev is: " << prev << "\n";
        //         str1[prev] = str2[i];
        //     }
        //     else
        //     {
        //         prev = *itr;
        //         cout << "Prev1 is: " << prev << "\n";
        //     }
        // }
        // for (int i = 0; i < str1.length(); i++)
        // {
        //     if (str1[i] == '?')
        //     {
        //         str1[i] = 'a';
        //     }
        // }
        // if (possible)
        // {
        //     cout << "YES\n";
        //     cout << str1 << "\n";
        // }
        // else
        // {
        //     cout << "NO\n";
        // }
    }
    return 0;
}
