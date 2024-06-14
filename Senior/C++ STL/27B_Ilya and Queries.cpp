#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    string str;
    cin >> str;
    ll q;
    cin >> q;
    ll len = str.length();
    vector<ll> pref(len + 1, 0);
    for (ll i = len - 1; i >= 0; i--)
    {
        pref[i] = pref[i + 1];
        if (str[i] == str[i + 1])
        {
            pref[i] = pref[i + 1] + 1;
        }
    }
    // for (auto i : pref)
    // {
    //     cout << i << " ";
    // }
    // cout << '\n';
    while (q--)
    {
        ll left, right;
        cin >> left >> right;
        cout << abs(pref[right - 1] - pref[left - 1]) << "\n";
    }
    return 0;
}