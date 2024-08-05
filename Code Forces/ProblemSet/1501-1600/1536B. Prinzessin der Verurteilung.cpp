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

char findLength1(string &str)
{
    vector<ll> freq(26, 0);
    for (char ch : str)
    {
        freq[ch - 'a']++;
    }
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        if (freq[ch - 'a'] == 0)
        {
            return ch;
        }
    }
    return ' ';
}
string findLength2(string &str)
{
    set<string> possible;
    for (ll i = 0; i < str.length() - 1; i++)
    {
        string s = str.substr(i, 2);
        possible.insert(s);
    }
    for (char c1 = 'a'; c1 <= 'z'; c1++)
    {
        for (char c2 = 'a'; c2 <= 'z'; c2++)
        {
            string s = "";
            s += c1;
            s += c2;
            if (possible.find(s) == possible.end())
            {
                return s;
            }
        }
    }
    return "";
}
string findLength3(string &str)
{
    set<string> possible;
    for (ll i = 0; i < str.length() - 2; i++)
    {
        string s = str.substr(i, 3);
        possible.insert(s);
    }
    for (char c1 = 'a'; c1 <= 'z'; c1++)
    {
        for (char c2 = 'a'; c2 <= 'z'; c2++)
        {
            for (char c3 = 'a'; c3 <= 'z'; c3++)
            {
                string s = "";
                s += c1;
                s += c2;
                s += c3;
                if (possible.find(s) == possible.end())
                {
                    return s;
                }
            }
        }
    }
    return "";
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
        char len1 = findLength1(str);
        if (len1 != ' ')
        {
            cout << len1 << "\n";
            continue;
        }

        string len2 = findLength2(str);
        if (len2.length() != 0)
        {
            cout << len2 << "\n";
            continue;
        }

        string len3 = findLength3(str);
        if (len3.length() != 0)
        {
            cout << len3 << "\n";
            continue;
        }
    }
    return 0;
}