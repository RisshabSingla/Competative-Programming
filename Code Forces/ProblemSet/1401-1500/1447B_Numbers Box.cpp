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
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> arr(n, vector<ll>(m));
        ll sum = 0;
        bool zeroPresent = false;
        ll minElement = INT_MAX;
        ll negCount = 0;
        for (ll i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
                sum += abs(arr[i][j]);
                if (arr[i][j] == 0)
                {
                    zeroPresent = true;
                }
                if (arr[i][j] < 0)
                {
                    negCount++;
                }
                minElement = min(minElement, abs(arr[i][j]));
            }
        }
        if (negCount % 2)
        {
            cout << sum - 2 * minElement << '\n';
        }
        else
        {
            cout << sum << "\n";
        }
    }
    return 0;
}