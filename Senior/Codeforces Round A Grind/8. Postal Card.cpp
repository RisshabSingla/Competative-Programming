#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    ll n, m;
    cin >> n >> m;
    unordered_map<string, int> mp;
    while (n--)
    {
        string str;
        cin >> str;
        mp[str.substr(3)]++;
    }
    ll count = 0;
    unordered_map<string, int> mp2;
    while (m--)
    {
        string str;
        cin >> str;
        mp2[str]++;
    }
    for (auto i : mp2)
    {
        count += mp[i.first];
    }
    cout << count;
    return 0;
}