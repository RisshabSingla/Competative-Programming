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
    ll n, m;
    cin >> n >> m;
    multiset<int> st1;
    vector<ll> arr2(m);
    for (ll i = 0; i < n; i++)
    {
        ll t;
        cin >> t;
        st1.insert(t);
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    for (ll i = 0; i < m; i++)
    {
        auto itr = st1.upper_bound(arr2[i]);
        if (itr == st1.begin())
        {
            cout << -1 << "\n";
            continue;
        }
        --itr;
        cout << *itr << "\n";
        st1.erase(itr);
    }
    return 0;
}