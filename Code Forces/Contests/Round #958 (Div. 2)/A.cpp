#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <set>

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
        ll n, k;
        cin >> n >> k;
        // if (n == 1)
        // {
        //     cout << 0 << '\n';
        //     continue;
        // }

        // if (k == 2)
        // {
        //     cout << n - 1 << "\n";
        //     continue;
        // }
        // cout << max(n / (k - 1), 1LL) << "\n";

        multiset<ll> st;
        st.insert(n);
        ll count = 0;
        while ((*st.rbegin()) != 1)
        {
            int val = *st.rbegin();
            // cout << "Val is:" << val << "\n";
            st.erase(val);
            st.insert(max(val - k + 1, 1LL));
            count++;
        }
        cout << count << "\n";
    }
    return 0;
}
