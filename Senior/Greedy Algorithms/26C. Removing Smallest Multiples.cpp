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
        ll cost = 0;
        vector<bool> changed(n, false);
        for (ll i = 1; i <= n; i++)
        {
            if (str[i - 1] == '1')
            {
                continue;
            }
            ll index = i;
            while (index <= n && str[index - 1] == '0')
            {
                if (!changed[index - 1])
                {
                    cost += i;
                }
                changed[index - 1] = true;
                // cout << "Adding: " << i << "\n";
                // str[((index * mul) - 1)] = '1';
                index += i;
            }
        }
        cout << cost << "\n";
    }
    return 0;
}