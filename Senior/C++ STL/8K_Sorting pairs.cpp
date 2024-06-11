#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

bool comp(pair<int, string> &a, pair<int, string> &b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first > b.first;
}

int main()
{
    ll n;
    cin >> n;
    vector<pair<int, string>> arr(n);
    string str;
    ll num;
    for (int i = 0; i < n; i++)
    {
        cin >> str >> num;
        arr[i] = {num, str};
    }
    sort(arr.begin(), arr.end(), comp);
    for (auto i : arr)
    {
        cout << i.second << " " << i.first << "\n";
    }
    return 0;
}