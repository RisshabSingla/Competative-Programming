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
        string str;
        cin >> str;
        if (n % 2)
        {
            cout << "-1\n";
            continue;
        }

        ll first = 0;
        ll last = n - 1;
        ll k = 300;
        vector<ll> ans;
        while (k-- && first < last)
        {
            if (str[first] == str[last] && str[first] == '0')
            {
                str.insert(last + 1, "01");
                ans.push_back(last + 1);
                last++;
                first++;
            }
            else if (str[first] == str[last] && str[first] == '1')
            {
                str.insert(first, "01");
                ans.push_back(first);
                last++;
                first++;
            }
            else
            {
                last--;
                first++;
            }
        }

        if (first < last)
        {
            cout << -1 << "\n";
            continue;
        }

        cout << ans.size() << "\n";
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}