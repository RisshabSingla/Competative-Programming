#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
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
        map<ll, vector<ll>> mp;
        vector<ll> arr(n, 0);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i]].push_back(i + 1);
        }
        bool hasAns = true;
        for (auto &i : mp)
        {
            if (i.second.size() < 2)
            {
                hasAns = false;
            }
        }
        if (!hasAns)
        {
            cout << -1 << "\n";
            continue;
        }
        else
        {
            for (auto &i : mp)
            {
                ll size = i.second.size();
                if (size % 2 == 0)
                {
                    for (ll j = size - 1; j >= 0; j--)
                    {
                        cout << i.second[j] << " ";
                    }
                }
                else
                {
                    cout << i.second[size - 1] << " ";
                    for (ll j = 0; j < size - 1; j++)
                    {
                        cout << i.second[j] << " ";
                    }
                }
            }
        }
        cout << "\n";
    }
    return 0;
}