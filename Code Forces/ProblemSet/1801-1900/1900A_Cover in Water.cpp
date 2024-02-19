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
        vector<char> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if (n < 3)
        {
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] == '.')
                {
                    ++count;
                }
            }
            cout << count << "\n";
            continue;
        }
        bool three = false;
        for (int i = 2; i < n; i++)
        {
            if (arr[i - 2] == '.' && arr[i - 1] == '.' && arr[i] == '.')
            {
                three = true;
                break;
            }
        }
        if (three)
        {
            cout << "2"
                 << "\n";
            continue;
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == '.')
            {
                ++count;
            }
        }
        cout << count << '\n';
    }
    return 0;
}