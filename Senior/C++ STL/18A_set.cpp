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
    ll q;
    cin >> q;
    set<ll> st;
    while (q--)
    {
        string str;
        ll num;
        cin >> str >> num;
        if (str[0] == 'i')
        {
            st.insert(num);
        }
        else if (str[0] == 'l')
        {
            auto itr = st.lower_bound(num);
            // auto itr = lower_bound(st.begin(), st.end(), num);
            if (itr == st.end())
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << *itr << "\n";
            }
        }
        else if (str[0] == 'u')
        {
            // auto itr = upper_bound(st.begin(), st.end(), num);
            auto itr = st.upper_bound(num);
            if (itr == st.end())
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << *itr << "\n";
            }
        }
        else
        {
            if (st.count(num))
            {
                cout << "found\n";
            }
            else
            {
                cout << "not found\n";
            }
        }
        // cout << "Set is: ";
        // for (auto i : st)
        // {
        //     cout << i << ' ';
        // }
        // cout << "\n";
    }
    return 0;
}