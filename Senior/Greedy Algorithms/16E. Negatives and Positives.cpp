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
        vector<ll> arr(n);
        ll sum = 0;
        ll neg = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] <= 0)
            {
                neg++;
            }
        }
        sort(arr.begin(), arr.end());
        if (neg % 2)
        {
            ll mini = LLONG_MAX;
            for (ll i = 0; i < n; i++)
            {
                mini = min(mini, abs(arr[i]));
            }
            bool taken = false;
            for (ll i = 0; i < n; i++)
            {
                if (abs(arr[i]) == mini && !taken)
                {
                    sum += (-mini);
                    taken = true;
                    continue;
                }
                sum += abs(arr[i]);
            }
            cout << sum << '\n';
        }
        else
        {
            for (ll i = 0; i < n; i++)
            {
                sum += abs(arr[i]);
            }
            cout << sum << '\n';
        }
    }
    return 0;
}