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
    set<ll> st;
    for (ll i = 0; i < n; i++)
    {
        ll t;
        cin >> t;
        st.insert(t);
    }
    vector<ll> arr;
    for (auto i : st)
    {
        arr.push_back(i);
    }
    n = st.size();
    while (q--)
    {
        ll t;
        cin >> t;
        ll index1 = lower_bound(arr.begin(), arr.end(), t) - arr.begin();
        ll index2 = n - (upper_bound(arr.begin(), arr.end(), t) - arr.begin());
        cout << index1 << " " << index2 << "\n";
    }
    return 0;
}