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
    vector<ll> powers(19, 1);
    for (ll i = 1; i < 19; i++)
    {
        powers[i] = powers[i - 1] * 10;
    }

    while (cases--)
    {
        ll n;
        cin >> n;
        ll numDigits = 0;
        ll digitLength = 0;
        ll prevDigits = 0;
        for (int i = 1; i < 19; i++)
        {
            digitLength += (powers[i] - powers[i - 1]) * i;
            if (digitLength >= n)
            {
                numDigits = i;
                break;
            }
            prevDigits = digitLength;
        }
        ll low = powers[numDigits - 1];
        ll high = powers[numDigits] - 1;
        ll ans = 0;
        ll startPosAns = 0;
        while (low <= high)
        {
            ll mid = low + (high - low) / 2;

            ll startPosition = (mid - powers[numDigits - 1]) * numDigits + prevDigits + 1;

            if (startPosition <= n)
            {
                if (mid > ans)
                {
                    ans = mid;
                    startPosAns = startPosition;
                }
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        string number = to_string(ans);
        cout << number[n - startPosAns] << "\n";
    }

    return 0;
}