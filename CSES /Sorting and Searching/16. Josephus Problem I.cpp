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
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    while (arr.size() > 1)
    {
        vector<int> other;
        for (int i = 1; i < arr.size(); i += 2)
        {
            cout << arr[i] << " ";
        }
        for (int i = 0; i < arr.size(); i += 2)
        {
            other.push_back(arr[i]);
        }
        if (arr.size() % 2 == 0)
        {
            arr = other;
        }
        else
        {
            int last = other.back();
            other.pop_back();
            arr.clear();
            arr.push_back(last);
            for (auto j : other)
            {
                arr.push_back(j);
            }
        }
    }
    cout << arr[0] << " ";
    return 0;
}