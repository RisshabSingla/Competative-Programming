#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<pll> vpl;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<double> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    double currSum = 0;
    ll index = 0;
    while (index < k)
    {
        currSum += arr[index];
        index++;
    }
    double sum = currSum;
    for (ll i = 0; i + k < n; i++)
    {
        currSum -= arr[i];
        currSum += arr[i + k];
        sum += currSum;
    }
    // cout << "Sum is: " << sum << "\n";
    cout << fixed << setprecision(10) << sum / (double)(n - k + 1) << "\n";
    return 0;
}