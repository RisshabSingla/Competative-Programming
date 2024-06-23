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
    ll n;
    cin >> n;
    vector<ll> ans;
    while (n >= 2)
    {
        ans.push_back(2);
        n -= 2;
    }
    if (n == 1)
    {
        ans.pop_back();
        ans.push_back(3);
    }
    cout << ans.size() << "\n";
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}