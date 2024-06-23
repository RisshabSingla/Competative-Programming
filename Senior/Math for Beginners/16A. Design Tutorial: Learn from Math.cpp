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
    ll n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << 4 << " " << n - 4;
    }
    else
    {
        cout << 9 << " " << n - 9;
    }

    return 0;
}