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
    int arr[int(1e6)];
    arr[0] = 0;
    for (int i = 1; i < 1e6; i++)
    {
        arr[i] = i xor arr[i - 1];
    }

    while (cases--)
    {
        ll a, b;
        cin >> a >> b;
        ll curr = arr[a - 1];
        // for (ll i = 1; i < a; i++)
        // {
        //     curr = curr xor i;
        // }
        if (curr == b)
        {
            cout << a << "\n";
            continue;
        }
        ll req = curr xor b;
        if (req != a)
        {
            cout << a + 1 << "\n";
        }
        else
        {
            cout << a + 2 << "\n";
        }
    }
    return 0;
}