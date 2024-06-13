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
    ll moves = 0;
    ll prev;
    cin >> prev;
    for (int i = 0; i < n - 1; i++)
    {
        ll elem;
        cin >> elem;
        moves += max(prev - elem, 0LL);
        prev = elem + max(prev - elem, 0LL);
    }
    cout << moves << endl;

    return 0;
}