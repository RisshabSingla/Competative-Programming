#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<pll> vpl;
typedef vector<int> vi;

const int mod = 1000000007;

bool isPossible(map<ll, ll> &mp, ll workers, ll timeGiven)
{
    ll extraJobs = 0;
    ll extraWorkers = 0;
    for (ll i = 1; i <= workers; i++)
    {
        if (mp[i] < timeGiven)
        {
            extraWorkers += ((timeGiven - mp[i]) / 2);
        }
        else
        {
            extraJobs += (mp[i] - timeGiven);
        }
    }
    // cout << "Time is: " << timeGiven << " jobs: " << extraJobs << " workers: " << extraWorkers << "\n";
    return (extraJobs) <= extraWorkers;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n, m;
        cin >> n >> m;
        map<ll, ll> mp;
        for (ll i = 0; i < m; i++)
        {
            ll t;
            cin >> t;
            mp[t]++;
        }
        ll low = 0;
        ll high = 4e6;
        ll ans = 0;
        while (low <= high)
        {
            ll mid = low + (high - low) / 2;
            if (isPossible(mp, n, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}