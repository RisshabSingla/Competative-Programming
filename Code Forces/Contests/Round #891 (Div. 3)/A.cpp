#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

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
        int n;
        cin >> n;
        vector<int> arr(n);
        int odds = 0;
        int evens = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] % 2 == 1)
            {
                odds++;
            }
            else
            {
                evens++;
            }
        }

        // cout << "Odds: " << odds << " evens: " << evens << endl;

        if (odds == 0)
        {
            cout << "YES" << endl;
            continue;
        }

        if (evens == 0)
        {
            if (n % 2 == 0)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
            continue;
        }
        if (odds == evens)
        {
            if (odds % 2 == 0)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
            continue;
        }
        if (n % 2 == 0)
        {
            if (evens % 2 == 0 && odds % 2 == 0)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
            continue;
        }

        if (n % 2 == 1)
        {
            if (odds % 2 == 0)
            {
                cout << "YES" << endl;
                continue;
            }
        }
        cout << "NO" << endl;
    }

    return 0;
}
