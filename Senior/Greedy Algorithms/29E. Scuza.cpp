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
        ll n, q;
        cin >> n >> q;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<ll> lengthReq(n);
        ll stepReq = arr[0];
        lengthReq[0] = arr[0];
        vector<ll> pref(n, 0);
        pref[0] = arr[0];
        for (ll i = 1; i < n; i++)
        {
            stepReq = max(stepReq, arr[i]);
            lengthReq[i] = stepReq;
            pref[i] += pref[i - 1];
            pref[i] += arr[i];
        }
        while (q--)
        {
            ll t;
            cin >> t;
            if (t < arr[0])
            {
                cout << 0 << " ";
                continue;
            }
            auto itr = upper_bound(lengthReq.begin(), lengthReq.end(), t);
            itr--;
            ll index = itr - lengthReq.begin();
            cout << pref[index] << " ";
        }
        cout << "\n";
    }
    return 0;
}