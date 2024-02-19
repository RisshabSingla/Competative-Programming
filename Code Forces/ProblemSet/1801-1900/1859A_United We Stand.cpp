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
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        vector<ll> a;
        vector<ll> b;
        int index = 0;
        while (arr[index] == arr[0])
        {
            a.push_back(arr[index]);
            index++;
        }
        while (index < n)
        {
            b.push_back(arr[index]);
            index++;
        }
        if (b.size() == 0)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << a.size() << " " << b.size() << "\n";
            for (auto i : a)
            {
                cout << i << " ";
            }
            cout << "\n";
            for (auto i : b)
            {
                cout << i << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}