#include <iostream>
#include <vector>
#include <queue>
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
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // priority_queue<ll, vector<ll>, greater<ll>> pq;
    // pq.push(arr[0]);
    // for (ll i = 1; i < n; i++)
    // {
    //     if (pq.top() > arr[i])
    //     {
    //         pq.pop();
    //         pq.push(arr[i]);
    //     }
    //     else
    //     {
    //         vector<ll> ans;
    //         while (!pq.empty() && pq.top() <= arr[i])
    //         {
    //             ans.push_back(pq.top());
    //             pq.pop();
    //         }
    //         if (!pq.empty())
    //         {
    //             pq.pop();
    //         }
    //         pq.push(arr[i]);
    //         for (auto j : ans)
    //         {
    //             pq.push(j);
    //         }
    //     }
    // }
    // cout << pq.size() << "\n";

    vector<ll> ans;
    for (ll i = 0; i < n; i++)
    {
        auto itr = upper_bound(ans.begin(), ans.end(), arr[i]);
        if (itr == ans.end())
        {
            ans.push_back(arr[i]);
        }
        else
        {
            *itr = arr[i];
        }
    }
    cout << ans.size() << "\n";
    return 0;
}