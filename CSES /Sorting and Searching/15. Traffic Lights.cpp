#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    int x, n;
    cin >> x >> n;
    multiset<int> length;
    set<int> positions;
    positions.insert(0);
    positions.insert(x);
    length.insert(x);
    for (int i = 0; i < n; i++)
    {
        int pos;
        cin >> pos;
        positions.insert(pos);
        auto itr = positions.find(pos);
        int previousValue = *prev(itr);
        int nextValue = *next(itr);
        length.erase(length.find(nextValue - previousValue));
        length.insert(pos - previousValue);
        length.insert(nextValue - pos);
        cout << *length.rbegin() << " ";
    }

    return 0;
}