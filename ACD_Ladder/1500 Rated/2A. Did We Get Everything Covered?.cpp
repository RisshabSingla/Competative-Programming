#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

// bool checkPossible(string &str1, string &str2)
// {
//     ll index = 0;
//     for (ll i = 0; i < str2.length(); i++)
//     {
//         if (str1[index] == str2[i])
//         {
//             index++;
//         }
//     }
//     return index == str1.length();
// }

// string findAns(ll n, ll k, string &str, string &curr, char &end)
// {
//     if (n == 0)
//     {
//         if (!checkPossible(curr, str))
//         {
//             return curr;
//         }
//         return "";
//     }
//     for (char ch = 'a'; ch <= end; ch++)
//     {
//         curr.push_back(ch);
//         string ans = findAns(n - 1, k, str, curr, end);
//         if (ans != "")
//         {
//             return ans;
//         }
//         curr.pop_back();
//     }
//     return "";
// }

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n, k, m;
        cin >> n >> k >> m;
        string str;
        cin >> str;

        set<char> st;
        string ans = "";
        for (ll i = 0; i < m; i++)
        {
            st.insert(str[i]);
            if (st.size() == k)
            {
                ans.push_back(str[i]);
                st.clear();
            }
        }
        if (ans.length() >= n)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                if (!st.count(ch))
                {
                    while (ans.length() < n)
                    {
                        ans.push_back(ch);
                    }
                    break;
                }
            }
            cout << ans << "\n";
        }

        // ll count = 0;
        // set<char> last;
        // vector<char> lasts;
        // for (ll i = 0; i < m; i++)
        // {
        //     set<char> st;
        //     char lastChar;
        //     while (i < m && st.size() != k)
        //     {
        //         st.insert(str[i]);
        //         lastChar = str[i];
        //         i++;
        //         // cout << "Size: " << st.size() << "\n";
        //         // cout << "Str[i]: " << str[i] << " i: " << i << "\n";
        //     }
        //     lasts.push_back(lastChar);
        //     // cout << "i is: " << i << "\n";
        //     if (i == m && st.size() != k)
        //     {
        //         if (count > 0)
        //         {
        //             count++;
        //         }
        //         last = st;
        //     }
        //     if (st.size() == k)
        //     {
        //         count++;
        //     }
        // }
        // // cout << "Count is: " << count << "\n";
        // if (count == k)
        // {
        //     cout << "YES\n";
        // }
        // else
        // {
        //     cout << "NO\n";
        //     if (last.size() == 0)
        //     {
        //         cout << "Empty\n";

        //     }
        //     // for (int i = 0; i < count; i++)
        //     // {
        //     //     cout << 'a';
        //     // }
        //     for (ll i = 0; i < min(n - 1, k - 1); i++)
        //     {
        //         cout << lasts[i];
        //     }
        //     // cout << "\nLast\n";
        //     // for (char i : last)
        //     // {
        //     //     cout << i;
        //     // }
        //     // cout << "\n";
        //     char end = 'a' + k - 1;
        //     for (char ch = 'a'; ch <= end; ch++)
        //     {
        //         if (!last.count(ch))
        //         {
        //             cout << ch;
        //             break;
        //         }
        //     }
        //     cout << "\n";
        // }

        // string curr = "";
        // char end = 'a' + k - 1;
        // string ans = findAns(n, k, str, curr, end);
        // if (ans == "")
        // {
        //     cout << "YES\n";
        // }
        // else
        // {
        //     cout << "NO\n";
        //     cout << ans << "\n";
        // }
    }
    return 0;
}