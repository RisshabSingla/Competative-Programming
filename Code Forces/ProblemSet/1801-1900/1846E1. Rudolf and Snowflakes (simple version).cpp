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
    int cases;
    cin >> cases;
    set<ll> st;
    ll maxi = 1e6 + 2;
    for (ll i = 2;; i++)
    {
        ll least = 1 + i + i * i;
        if (least >= maxi)
        {
            break;
        }
        ll num = i * i * i;
        while (least < maxi)
        {
            st.insert(least);
            least += num;
            num *= i;
        }
    }
    while (cases--)
    {
        ll n;
        cin >> n;
        if (st.count(n))
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