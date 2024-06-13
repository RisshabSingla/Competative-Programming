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
    ll num = (n) * (n + 1);
    if (num % 4 != 0)
    {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    vector<ll> arr1;
    vector<ll> arr2;

    ll number = n;
    bool turn = true;
    while (number)
    {
        if (turn)
        {
            arr1.push_back(number);
            number--;
            if (number)
            {
                arr2.push_back(number);
                number--;
            }
        }
        else
        {
            arr2.push_back(number);
            number--;
            if (number)
            {
                arr1.push_back(number);
                number--;
            }
        }
        turn = turn ? false : true;
    }
    cout << arr1.size() << '\n';
    for (auto i : arr1)
    {
        cout << i << " ";
    }
    cout << '\n'
         << arr2.size() << '\n';
    for (auto i : arr2)
    {
        cout << i << " ";
    }

    return 0;
}