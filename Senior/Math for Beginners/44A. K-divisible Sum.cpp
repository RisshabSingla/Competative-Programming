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
        ll n, k;
        cin >> n >> k;
        ll multiple = n / k;
        if (n % k)
        {
            multiple++;
        }
        k = k * multiple;
        ll maxi = k / n;
        if (k % n)
        {
            maxi++;
        }

        cout << maxi << "\n";
    }
    return 0;
}