#include <iostream>
#include <vector>
#include <algorithm>
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
        ll n, k;
        cin >> n >> k;
        vector<ll> arr(k);
        for (ll i = 0; i < k; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        priority_queue<ll> pq;
        for (ll i = 1; i < k; i++)
        {
            pq.push(arr[i] - arr[i - 1] - 1);
        }
        pq.push((n - arr.back() + (arr[0] - 1)));
        ll curr = 0;
        ll saved = 0;
        while (!pq.empty())
        {
            ll top = pq.top();
            pq.pop();
            // cout << "TOP is: " << top << "\n";
            if (top <= 2 * curr)
            {
                break;
            }
            top -= 2 * curr;
            if (top == 1)
            {
                saved++;
                curr++;
            }
            else
            {
                saved += (top - 1);
                curr += 2;
            }
        }
        cout << n - saved << "\n";
    }
    return 0;
}