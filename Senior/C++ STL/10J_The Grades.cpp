#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

bool comp(pair<vector<ll>, string> &a, pair<vector<ll>, string> &b)
{
    if (a.first[0] == b.first[0])
    {
        return a.second < b.second;
    }
    return a.first[0] > b.first[0];
}

int main()
{
    ll n;
    cin >> n;
    vector<pair<vector<ll>, string>> arr(n);
    string str;
    ll a, b, c, d;
    for (int i = 0; i < n; i++)
    {
        cin >> str >> a >> b >> c >> d;
        ll sum = a + b + c + d;
        arr[i] = {{sum, a, b, c, d}, str};
    }
    sort(arr.begin(), arr.end(), comp);
    for (auto i : arr)
    {
        cout << i.second << " ";
        for (auto j : i.first)
        {
            cout << j << ' ';
        }
        cout << "\n";
    }
    return 0;
}