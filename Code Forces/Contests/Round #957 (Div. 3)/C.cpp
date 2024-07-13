#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

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
        ll n, m, k;
        cin >> n >> m >> k;
        vector<int> ans(n, 0);
        int num = 1;
        for (int i = n - m; i < n; i++)
        {
            ans[i] = num;
            num++;
        }

        num = n;
        for (int i = 0; i < n - m; i++)
        {
            ans[i] = num;
            num--;
        }
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
