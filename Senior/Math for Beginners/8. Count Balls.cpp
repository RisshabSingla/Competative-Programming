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
    ll n, a, b;
    cin >> n >> a >> b;
    ll nSeq = n / (a + b);
    ll left = n % (a + b);
    cout << a * nSeq + min(left, a);
    return 0;
}