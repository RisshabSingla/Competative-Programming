#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>

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
        ll n, m, d;
        cin >> n >> m >> d;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] < 0)
            {
                arr[i] = 0;
            }
        }
        ll sum = 0;
        ll ans = 0;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (ll i = 0; i < n; i++)
        {
            if (arr[i] > 0)
            {
                sum += arr[i];
                pq.push(arr[i]);
            }

            if (pq.size() > m)
            {
                sum -= pq.top();
                pq.pop();
            }
            ans = max(ans, sum - d * (i + 1));
        }
        cout << ans << endl;
        // ll front = 0;
        // ll back = 0;
        // ll sum = 0;
        // while (back < m && back < n)
        // {
        //     sum += arr[back];
        //     back++;
        // }
        // ll max_possible = max(sum - d * (back), 0LL);
        // while (back < n)
        // {
        //     if (back - front == m)
        //     {
        //         sum -= arr[front];
        //         front++;
        //         ll possible = sum - d * (back);
        //         max_possible = max(max_possible, possible);
        //     }
        //     sum += arr[back];
        //     ll possible = sum - d * (back);
        //     back++;
        //     max_possible = max(max_possible, possible);
        // }
        // cout << max_possible << endl;
    }
    return 0;
}
