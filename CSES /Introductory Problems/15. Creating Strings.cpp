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

void recur(string &str, int index, int n, set<string> &st)
{
    if (index == n)
    {
        st.insert(str);
        return;
    }

    for (int i = index; i < n; i++)
    {
        swap(str[i], str[index]);
        recur(str, index + 1, n, st);
        swap(str[i], str[index]);
    }
}

int main()
{
    string str;
    cin >> str;
    set<string> st;

    recur(str, 0, str.length(), st);

    cout << st.size() << "\n";
    for (auto &i : st)
    {
        cout << i << "\n";
    }

    return 0;
}