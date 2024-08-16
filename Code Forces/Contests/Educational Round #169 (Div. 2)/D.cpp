#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

vector<string> vec = {"BG", "BR", "BY", "GR", "GY", "RY"};

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n, q;
        cin >> n >> q;
        vector<string> a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<vector<ll>> mp(6);
        for (int i = 0; i < n; i++)
        {
            if (a[i] == "BG")
            {
                mp[0].push_back(i);
            }
            if (a[i] == "BR")
            {
                mp[1].push_back(i);
            }
            if (a[i] == "BY")
            {
                mp[2].push_back(i);
            }
            if (a[i] == "GR")
            {
                mp[3].push_back(i);
            }
            if (a[i] == "GY")
            {
                mp[4].push_back(i);
            }
            if (a[i] == "RY")
            {
                mp[5].push_back(i);
            }
        }
        while (q--)
        {
            ll i, j;
            cin >> i >> j;
            i--;
            j--;
            set<char> stt;
            for (auto ch : a[j])
            {
                stt.insert(ch);
            }
            for (auto ch : a[i])
            {
                stt.insert(ch);
            }
            if (stt.size() < 4)
            {
                cout << abs(i - j) << '\n';
                continue;
            }
            if (j < i)
            {
                swap(i, j);
            }
            ll left = -1;
            ll right = n;
            for (ll k = 0; k < 6; k++)
            {
                string str = vec[k];
                if (str == a[i] || str == a[j])
                    continue;
                auto it = lower_bound(mp[k].begin(), mp[k].end(), i);
                if (it != mp[k].begin())
                {
                    it--;
                    left = max(left, *it);
                }

                it = upper_bound(mp[k].begin(), mp[k].end(), i);
                if (it != mp[k].end())
                {
                    right = min(right, *it);
                }
            }
            if (left == -1 && right == n)
            {
                cout << "-1\n";
            }
            else if (left == -1)
            {
                cout << abs(i - right) + abs(j - right) << '\n';
            }
            else if (right == n)
            {
                cout << abs(i - left) + abs(j - left) << '\n';
            }
            else
            {
                ll ans = min(abs(i - left) + abs(j - left), abs(i - right) + abs(j - right));
                cout << ans << '\n';
            }
        }
    }
    return 0;
}
