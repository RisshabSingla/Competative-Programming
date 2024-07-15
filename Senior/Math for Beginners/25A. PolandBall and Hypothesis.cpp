#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ll n;
    cin >> n;
    for (ll i = 1; i <= 1000; i++)
    {
        if (!isPrime(n * i + 1))
        {
            cout << i << "\n";
            break;
        }
    }
    return 0;
}