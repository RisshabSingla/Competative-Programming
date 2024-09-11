#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<pll> vpl;
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
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        set<ll> st1;
        set<ll> st2;
        vector<ll> arr1(n, 0);
        vector<ll> arr2(n, 0);
        bool flag = true;
        for (ll i = 0; i < n; i++)
        {
            if (!st1.count(arr[i]))
            {
                arr1[i] = arr[i];
                st1.insert(arr[i]);
            }
            else if (!st2.count(arr[i]))
            {
                arr2[i] = arr[i];
                st2.insert(arr[i]);
            }
            else
            {
                flag = false;
            }
        }
        if (!flag)
        {
            cout << "NO\n";
            continue;
        }

        set<ll> rem1;
        set<ll> rem2;
        for (ll i = 1; i <= n; i++)
        {
            if (!st1.count(i))
            {
                rem1.insert(i);
            }
            if (!st2.count(i))
            {
                rem2.insert(i);
            }
        }
        for (ll i = 0; i < n; i++)
        {
            if (arr1[i] == 0)
            {
                auto itr = rem1.upper_bound(arr2[i]);
                if (itr == rem1.begin())
                {
                    flag = false;
                    break;
                }
                itr = prev(itr);
                arr1[i] = *itr;
                rem1.erase(itr);
            }

            if (arr2[i] == 0)
            {
                auto itr = rem2.upper_bound(arr1[i]);
                if (itr == rem2.begin())
                {
                    flag = false;
                    break;
                }
                itr = prev(itr);
                arr2[i] = *itr;
                rem2.erase(itr);
            }
        }
        if (!flag)
        {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for (auto i : arr1)
        {
            cout << i << ' ';
        }
        cout << "\n";
        for (auto i : arr2)
        {
            cout << i << ' ';
        }
        cout << "\n";
    }
    return 0;
}