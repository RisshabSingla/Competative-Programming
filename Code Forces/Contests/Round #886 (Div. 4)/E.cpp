#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

bool calcarea(vector<ull> &arr, ull border, ull n, ull given_area)
{
    __int128_t area = 0;
    for (ull i = 0; i < n; i++)
    {

        // cout << "Adding: " << ((arr[i] + 2 * border) * (arr[i] + 2 * border)) << " arr[i] is: " << arr[i] << endl;
        area += ((arr[i] + 2 * border) * (arr[i] + 2 * border));
    }
    return area >= given_area;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ull n, area;
        cin >> n >> area;
        vector<ull> arr(n);
        ull sq = 0;
        for (ull i = 0; i < n; i++)
        {
            cin >> arr[i];
            sq += (arr[i] * arr[i]);
        }
        if (sq == area)
        {
            cout << 0 << endl;
            continue;
        }
        int low = 0;
        int high = int(1e10);
        while (low < high - 1)
        {
            int mid = low + (high - low) / 2;
            if (calcarea(arr, mid, n, area))
            {
                high = mid;
            }
            else
            {
                low = mid;
            }
        }
        cout << high << endl;
    }
    return 0;
}
