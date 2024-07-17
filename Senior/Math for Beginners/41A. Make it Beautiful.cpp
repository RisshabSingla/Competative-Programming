#include <iostream>
#include <vector>
#include <algorithm>
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
        map<ll, ll> mp;
        for (ll i = 0; i < n; i++)
        {
            ll t;
            cin >> t;
            mp[t]++;
        }
        if (mp.size() == 1)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        vector<ll> arr1;
        vector<ll> arr2;
        for (auto &i : mp)
        {
            arr1.push_back(i.first);
            i.second--;
        }

        for (auto &i : mp)
        {
            for (ll j = 0; j < i.second; j++)
            {
                arr2.push_back(i.first);
            }
        }
        reverse(arr1.begin(), arr1.end());
        for (auto &i : arr1)
        {
            cout << i << " ";
        }
        for (auto &i : arr2)
        {
            cout << i << " ";
        }
        cout << '\n';
    }
    return 0;
}