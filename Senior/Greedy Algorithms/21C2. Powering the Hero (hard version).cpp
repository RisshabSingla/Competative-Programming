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
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        priority_queue<ll> pq;
        ll total = 0;
        for (ll i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                if (!pq.empty())
                {
                    total += pq.top();
                    pq.pop();
                }
            }
            else
            {
                pq.push(arr[i]);
            }
        }
        cout << total << "\n";
    }
    return 0;
}