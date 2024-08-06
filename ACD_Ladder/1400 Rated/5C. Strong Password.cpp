#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

bool isPossible2(string &str1, string &str2, ll index, ll m, ll prevIndex, vector<vector<ll>> &positions, ll n)
{
    if (index == m)
    {
        if (prevIndex < n)
        {
            return false;
        }
        return true;
    }
    ll start = str1[index] - '0';
    ll end = str2[index] - '0';
    ll maxi = -1;

    // cout << "Start: " << start << " end: " << end << " prev: " << prevIndex << " index: " << index << "\n";
    for (ll i = start; i <= end; i++)
    {
        auto itr = upper_bound(positions[i].begin(), positions[i].end(), prevIndex);
        if (itr == positions[i].end())
        {
            return true;
        }
        ll pos = itr - positions[i].begin();
        maxi = max(maxi, positions[i][pos]);
    }
    if (maxi <= prevIndex)
    {
        return false;
    }
    return isPossible2(str1, str2, index + 1, m, maxi, positions, n);
}

// bool isPossible(string &str1, string &str2, ll index, ll m, ll prevIndex, vector<vector<ll>> &positions, bool possible)
// {
//     if (index == m)
//     {
//         if (possible)
//         {
//             return false;
//         }
//         return true;
//     }
//     ll start = str1[index] - '0';
//     ll end = str2[index] - '0';
//     // cout << "Start: " << start << " end: " << end << " prev: " << prevIndex << " index: " << index << " m is: " << m << "\n";

//     for (ll i = start; i <= end; i++)
//     {
//         auto itr = upper_bound(positions[i].begin(), positions[i].end(), prevIndex);
//         ll pos = itr - positions[i].begin();
//         if (itr == positions[i].end())
//         {
//             return true;
//             // if (isPossible(str1, str2, index + 1, m, maxi, positions, false))
//             // {
//             //     return true;
//             // }
//         }
//         else
//         {
//             if (isPossible(str1, str2, index + 1, m, positions[i][pos], positions, true))
//             {
//                 return true;
//             }
//         }
//     }
//     return false;
// }

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        string str;
        cin >> str;
        vector<vector<ll>> position(10);
        for (ll i = 0; i < str.length(); i++)
        {
            position[str[i] - '0'].push_back(i);
        }
        ll m;
        cin >> m;
        string str1;
        cin >> str1;
        string str2;
        cin >> str2;
        ll n = str.length();
        if (isPossible2(str1, str2, 0, m, -1, position, n))
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