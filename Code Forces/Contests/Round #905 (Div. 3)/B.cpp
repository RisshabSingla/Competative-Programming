#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

bool solve(ll n, ll k, string &str)
{
    if (k > n)
    {
        return false;
    }
    if (k == n)
    {
        return true;
    }
    vector<int> freq(26, 0);
    for (int i = 0; i < n; i++)
    {
        freq[str[i] - 'a']++;
    }
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
    for (int i = 0; i < 26; i++)
    {

        if (freq[i] > 0)
        {
            pq.push({freq[i], 'a' + i});
        }
    }

    // string str = "";
    bool odd = false;
    int odd_freq;
    while (!pq.empty())
    {
        if (pq.top().first % 2 == 1)
        {
            if (!odd)
            {
                odd = true;
                odd_freq = pq.top().first;
            }
            else
            {
                k--;
            }
        }
        pq.pop();
    }
    if (k < 0)
    {
        return false;
    }
    if (n - k >= 0)
    {
        return true;
    }
    return false;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n, k;
        cin >> n >> k;
        string str;
        cin >> str;
        if (solve(n, k, str))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
