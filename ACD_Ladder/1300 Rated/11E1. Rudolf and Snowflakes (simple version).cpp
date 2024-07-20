#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    set<ll> st;
    ll maxi = 1e6 + 2;
    for (ll k = 2; k <= 1000; k++)
    {
        ll sum = 1 + k;
        ll curr = k * k;
        while (sum <= maxi)
        {
            sum += curr;
            st.insert(sum);
            curr *= k;
        }
    }

    int cases;
    cin >> cases;
    while (cases--)
    {
        ll t;
        cin >> t;
        if (st.count(t))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}