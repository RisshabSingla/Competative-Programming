#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

const ll MOD = 1000000007;

ll findEarliestTime(ll n, ll k, vi &installTimes)
{
    sort(installTimes.begin(), installTimes.end());

    ll latestInstallTime = installTimes.back();
    ll maxTimeToCheck = latestInstallTime + k;

    for (ll currentTime = latestInstallTime; currentTime <= maxTimeToCheck; ++currentTime)
    {
        bool allDevicesOn = true;
        for (ll i = 0; i < n; ++i)
        {
            ll elapsedTime = currentTime - installTimes[i];
            if (elapsedTime < 0 || elapsedTime % (2 * k) >= k)
            {
                allDevicesOn = false;
                break;
            }
        }
        if (allDevicesOn)
        {
            return currentTime;
        }
    }

    return -1;
}

int main()
{
    ll cases;
    cin >> cases;

    while (cases--)
    {
        ll n, k;
        cin >> n >> k;
        vi installationTimes(n);
        for (ll i = 0; i < n; ++i)
        {
            cin >> installationTimes[i];
        }

        cout << findEarliestTime(n, k, installationTimes) << '\n';
    }

    return 0;
}
