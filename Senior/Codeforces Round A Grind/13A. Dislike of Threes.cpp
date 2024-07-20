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
    vector<ll> arr(1001, 0);
    ll index = 0;
    ll num = 1;
    while (index < 1001)
    {
        if (num % 3 != 0 && num % 10 != 3)
        {
            arr[index] = num;
            index++;
        }
        num++;
    }
    while (cases--)
    {
        ll n;
        cin >> n;
        cout << arr[n - 1] << "\n";
    }
    return 0;
}