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
        vector<ll> arr(n);
        arr[0] = m;
        for (ll i = 1; i < n; i++)
        {
            cin >> arr[i];
        }

        vector<ll> brr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> brr[i];
        }
        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());
        ll index1 = 0;
        ll index2 = 0;
        ll count = 0;
        while (index1 < n && index2 < n)
        {
            if (arr[index1] < brr[index2])
            {
                index1++;
                index2++;
            }
            else
            {
                count++;
                index2++;
            }
        }
        cout << count << "\n";
    }
    return 0;
}