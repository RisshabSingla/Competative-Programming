#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <numeric>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

// ll findCount(string &str, ll n, char ch)
// {
//     bool del = false;
//     ll add = 0;
//     vector<ll> evens(26, 0);
//     vector<ll> odds(26, 0);
//     for (ll i = 0; i < n; i++)
//     {
//         // error due to this
//         // position after which we need to change
//         if (str[i] == ch && !del)
//         {
//             add = 1;
//             del = true;
//             continue;
//         }
//         ll index = i + add;
//         if (index % 2)
//         {
//             odds[str[i] - 'a']++;
//         }
//         else
//         {
//             evens[str[i] - 'a']++;
//         }
//     }
//     if (!del)
//     {
//         return INT_MAX;
//     }
//     ll count = 0;
//     ll evenMaxi = 0;
//     ll oddMaxi = 0;
//     for (ll i = 0; i < 26; i++)
//     {
//         evenMaxi = max(evenMaxi, evens[i]);
//         oddMaxi = max(oddMaxi, odds[i]);
//     }
//     count = (n / 2 - evenMaxi) + (n / 2 - oddMaxi);
//     // cout << "Count for: " << ch << " :" << count << "\n";
//     return count + 1;
// }

ll findAnsEven(string &str, ll n)
{
    vector<ll> evens(26, 0);
    vector<ll> odds(26, 0);
    for (ll i = 0; i < n; i++)
    {
        if (i % 2)
        {
            odds[str[i] - 'a']++;
        }
        else
        {
            evens[str[i] - 'a']++;
        }
    }
    ll count = 0;
    ll evenMaxi = 0;
    ll oddMaxi = 0;
    for (ll i = 0; i < 26; i++)
    {
        evenMaxi = max(evenMaxi, evens[i]);
        oddMaxi = max(oddMaxi, odds[i]);
    }
    count = (n / 2 - evenMaxi) + (n / 2 - oddMaxi);
    // cout << count << "\n";
    return count;
}

// ll findCount(vector<vector<ll>> &prefix, vector<vector<ll>> &suffix, ll index, ll n)
// {
//     vector<ll> evens(26, 0);
//     vector<ll> odds(26, 0);
//     for (ll i = 0; i < 26; i++)
//     {
//         if (index >= 2)
//         {
//             evens[i] += prefix[index - 2][i];
//         }
//         if (index + 1 < n)
//         {
//             evens[i] += suffix[index + 1][i];
//         }
//         if (index > 0)
//         {
//             odds[i] += prefix[index - 1][i];
//         }
//         if (index + 2 < n)
//         {
//             odds[i] += suffix[index + 1][i];
//         }
//     }

//     ll ans = 0;
//     ll maxiEven = *max_element(evens.begin(), evens.end());
//     ll evenCount = accumulate(evens.begin(), evens.end(), 0);
//     ll maxiOdd = *max_element(odds.begin(), odds.end());
//     ll oddCount = accumulate(odds.begin(), odds.end(), 0);
//     ans += (evenCount - maxiEven);
//     ans += (oddCount - maxiOdd);
//     return ans;
// }

ll findAnsOdd(string &str, ll n)
{
    vector<vector<ll>> prefix(n, vector<ll>(26, 0));
    vector<vector<ll>> suffix(n, vector<ll>(26, 0));
    for (ll i = 0; i < n; i++)
    {
        if (i >= 2)
        {
            prefix[i] = prefix[i - 2];
        }
        prefix[i][str[i] - 'a']++;
    }
    for (ll i = n - 1; i >= 0; i--)
    {
        if (i + 2 < n)
        {
            suffix[i] = suffix[i + 2];
        }
        suffix[i][str[i] - 'a']++;
    }

    ll ans = n;
    for (ll i = 0; i < n; i++)
    {
        // ans = min(ans, findCount(prefix, suffix, i, n));
    }
    return ans;
}

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

        if (n % 2 == 0)
        {
            cout << findAnsEven(str, n) << "\n";
        }
        else
        {
            cout << findAnsOdd(str, n) << "\n";
        }

        // if (n % 2 == 0)
        // {
        //     vector<ll> evens(26, 0);
        //     vector<ll> odds(26, 0);
        //     for (ll i = 0; i < n; i++)
        //     {
        //         if (i % 2)
        //         {
        //             odds[str[i] - 'a']++;
        //         }
        //         else
        //         {
        //             evens[str[i] - 'a']++;
        //         }
        //     }
        //     ll count = 0;
        //     ll evenMaxi = 0;
        //     ll oddMaxi = 0;
        //     for (ll i = 0; i < 26; i++)
        //     {
        //         evenMaxi = max(evenMaxi, evens[i]);
        //         oddMaxi = max(oddMaxi, odds[i]);
        //     }
        //     count = (n / 2 - evenMaxi) + (n / 2 - oddMaxi);
        //     cout << count << "\n";
        // }
        // else
        // {
        //     ll ans = INT_MAX;
        //     for (char ch = 'a'; ch <= 'z'; ch++)
        //     {
        //         ans = min(ans, findCount(str, n, ch));
        //     }
        //     cout << ans << "\n";
        // }
    }
    return 0;
}
