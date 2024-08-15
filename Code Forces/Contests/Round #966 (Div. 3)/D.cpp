#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

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
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<ll> pref(n, 0);
        pref[0] = arr[0];
        for (ll i = 1; i < n; i++)
        {
            pref[i] += pref[i - 1];
            pref[i] += arr[i];
        }
        string str;
        cin >> str;
        vector<ll> left;
        vector<ll> right;
        for (ll i = 0; i < n; i++)
        {
            if (str[i] == 'L')
            {
                left.push_back(i);
            }
            else
            {
                right.push_back(i);
            }
        }
        if (left.size() == 0 || right.size() == 0)
        {
            cout << 0 << "\n";
            continue;
        }
        ll index1 = 0;
        ll index2 = right.size() - 1;

        // while (index2 < right.size() && right[index2] < left.back())
        // {
        //     index2++;
        // }
        ll ans = 0;
        while (index2 >= 0 && index1 < left.size())
        {
            if (right[index2] >= left[index1])
            {
                ans += (pref[right[index2]] - pref[left[index1]]);
                ans += arr[left[index1]];
            }
            index2--;
            index1++;
        }
        cout << ans << "\n";
    }
    return 0;
}
