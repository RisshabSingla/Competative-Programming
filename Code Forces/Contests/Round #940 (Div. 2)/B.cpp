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
        ll n, k;
        cin >> n >> k;
        if (n == 1)
        {
            cout << k << "\n";
            continue;
        }
        vector<ll> ans;
        int pow = log2(k);
        ll num = (1LL << pow) - 1;
        ans.push_back(num);
        ll rem = k - num;
        ans.push_back(rem);
        for (int i = 0; i < n - 2; i++)
        {
            ans.push_back(0);
        }
        for (auto i : ans)
        {
            cout << i << ' ';
        }
        cout << "\n";
    }
    return 0;
}
