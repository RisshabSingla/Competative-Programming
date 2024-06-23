#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

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
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<ll> ans(n, -1);
    stack<ll> stk;
    for (ll i = 0; i < n; i++)
    {
        if (stk.empty())
        {
            stk.push(i);
            continue;
        }
        while (!stk.empty() && arr[stk.top()] >= arr[i])
        {
            stk.pop();
        }
        if (!stk.empty())
        {
            ans[i] = stk.top();
        }
        stk.push(i);
    }
    for (auto i : ans)
    {
        cout << i + 1 << " ";
    }

    return 0;
}