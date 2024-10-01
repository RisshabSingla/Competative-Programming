#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
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
        vector<ll> arr(n);
        ll noOfCards = 0;
        ll maxAmt = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            noOfCards += arr[i];
            maxAmt = max(maxAmt, arr[i]);
        }
        ll maxNoOfCards = noOfCards + k;
        ll ans = 1;
        for (ll deckSize = n; deckSize >= 1; deckSize--)
        {
            ll noOfDecks = maxNoOfCards / deckSize;
            ll totalUsedCards = deckSize * noOfDecks;
            if (totalUsedCards >= noOfCards && noOfDecks >= maxAmt)
            {
                ans = deckSize;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
