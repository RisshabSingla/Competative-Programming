#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> values(n + 1);
    vector<ll> positions(n + 1);

    for (ll i = 1; i <= n; i++)
    {
        cin >> values[i];
        positions[values[i]] = i;
    }
    ll count = 1;
    for (ll i = 1; i < n; i++)
    {
        // inversion
        count += (positions[i] > positions[i + 1]);
    }
    while (q--)
    {
        ll left, right;
        cin >> left >> right;
        set<pair<ll, ll>> st;
        if (values[left] + 1 <= n)
        {
            st.insert({values[left], values[left] + 1});
        }
        if (values[left] - 1 >= 1)
        {
            st.insert({values[left] - 1, values[left]});
        }
        if (values[right] + 1 <= n)
        {
            st.insert({values[right], values[right] + 1});
        }
        if (values[right] - 1 >= 1)
        {
            st.insert({values[right] - 1, values[right]});
        }

        for (auto i : st)
        {
            count -= (positions[i.first] > positions[i.second]);
        }
        swap(values[left], values[right]);
        positions[values[left]] = left;
        positions[values[right]] = right;
        for (auto i : st)
        {
            count += (positions[i.first] > positions[i.second]);
        }
        cout << count << "\n";
    }

    return 0;
}