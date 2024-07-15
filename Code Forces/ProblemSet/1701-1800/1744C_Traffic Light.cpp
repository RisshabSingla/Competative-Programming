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
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        char ch;
        cin >> ch;
        string str;
        cin >> str;
        if (ch == 'g')
        {
            cout << 0 << "\n";
            continue;
        }
        if (n == 1)
        {
            cout << 0 << "\n";
            continue;
        }
        vector<ll> indexes;
        for (ll i = 0; i < n; i++)
        {
            if (str[i] == 'g')
            {
                indexes.push_back(i);
            }
        }
        ll ans = 1;
        ll size = indexes.size();
        for (int i = 0; i < n; i++)
        {
            if (str[i] == ch)
            {
                ll index = lower_bound(indexes.begin(), indexes.end(), i) - indexes.begin();
                // cout<<"Index is: "
                if (index == size)
                {
                    ans = max(ans, indexes[0] + n - i);
                }
                else
                {
                    ans = max(ans, indexes[index] - i);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}