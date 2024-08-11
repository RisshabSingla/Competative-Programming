#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

ll countSubTrees(vector<vector<ll>> &arr, string &str, ll node, ll &count)
{
    if (arr[node].size() == 0)
    {
        if (str[node] == 'W')
        {
            return 1;
        }
        return -1;
    }
    ll sum = 0;
    if (str[node] == 'W')
    {
        sum++;
    }
    else
    {
        sum--;
    }
    for (auto child : arr[node])
    {
        sum += countSubTrees(arr, str, child, count);
    }
    if (sum == 0)
    {
        count++;
    }
    return sum;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        vector<vector<ll>> arr(n);
        for (ll i = 1; i < n; i++)
        {
            ll t;
            cin >> t;
            t--;
            arr[t].push_back(i);
        }
        string str;
        cin >> str;
        ll count = 0;
        countSubTrees(arr, str, 0, count);
        cout << count << "\n";
    }
    return 0;
}