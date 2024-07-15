#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

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
        vector<ll> arr(n);
        set<int> st;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int changes = 0;
        vector<ll> brr(n);
        map<int, int> mp;
        for (ll i = 0; i < n; i++)
        {
            cin >> brr[i];
            if (arr[i] != brr[i])
            {
                changes++;
                mp[brr[i]]++;
            }
            else
            {
                st.insert(arr[i]);
            }
        }
        // for (auto i : mp)
        // {
        //     cout << i.first << " " << i.second << "\n";
        // }
        // cout << "\n";
        ll m;
        cin >> m;
        vector<ll> drr(m);
        for (ll i = 0; i < m; i++)
        {
            cin >> drr[i];
        }

        if (changes > m)
        {
            cout << "NO\n";
            continue;
        }

        // cout << "Changes: " << changes << "\n";
        bool overRide = false;
        for (int i = 0; i < m; i++)
        {
            if (mp.count(drr[i]))
            {
                overRide = false;
                mp[drr[i]]--;
            }
            else
            {
                if (!st.count(drr[i]))
                {
                    overRide = true;
                }
                else
                {
                    overRide = false;
                }
            }
        }
        if (overRide)
        {
            cout << "NO\n";
        }
        else
        {
            bool ans = true;
            for (auto &i : mp)
            {
                // cout << i.first << " " << i.second << "\n";
                if (i.second > 0)
                {
                    ans = false;
                    break;
                }
            }
            if (!ans)
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";
            }
            // cout << "\n";
        }
    }
    return 0;
}