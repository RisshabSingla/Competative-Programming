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
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        ll mini = 1;
        ll maxi = n;
        ll left = 0;
        ll right = n - 1;
        while (left < right)
        {
            if (arr[left] == mini)
            {
                mini++;
                left++;
            }
            else if (arr[left] == maxi)
            {
                left++;
                maxi--;
            }
            else if (arr[right] == mini)
            {
                mini++;
                right--;
            }
            else if (arr[right] == maxi)
            {
                right--;
                maxi--;
            }
            else
            {
                break;
            }
        }
        if (left >= right)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << (left + 1) << " " << (right + 1) << "\n";
        }
    }
    return 0;
}