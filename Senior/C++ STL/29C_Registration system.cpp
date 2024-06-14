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
    ll n;
    cin >> n;
    unordered_map<string, int> mp;
    while (n--)
    {
        string str;
        cin >> str;
        if (mp.count(str))
        {
            cout << str << mp[str] << "\n";
        }
        else
        {
            cout << "OK\n";
        }
        mp[str]++;
    }
    return 0;
}