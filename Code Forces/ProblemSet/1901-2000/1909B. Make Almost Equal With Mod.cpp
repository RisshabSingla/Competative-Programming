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
    while (cases--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        ll ans = 2;
        while (true)
        {
            set<ll> st;
            for (auto i : arr)
            {
                st.insert(i % ans);
            }
            if (st.size() == 2)
            {
                break;
            }
            ans *= 2;
        }
        cout << ans << "\n";
    }
    return 0;
}