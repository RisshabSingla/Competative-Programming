#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
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
        string str;
        cin >> str;
        vector<ll> ans(n, -1);
        for (ll i = 0; i < n; i++)
        {
            if (ans[i] != -1)
            {
                continue;
            }
            ll count = 0;
            vector<bool> visited(n, false);
            ll current = i;
            while (!visited[current])
            {
                if (str[current] == '0')
                {
                    count++;
                }
                visited[current] = true;
                current = arr[current] - 1;
            }
            current = i;
            vector<bool> visited2(n, false);
            while (!visited2[current])
            {
                ans[current] = count;
                visited2[current] = true;
                current = arr[current] - 1;
            }
        }
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
