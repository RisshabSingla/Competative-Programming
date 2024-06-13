#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // flushes cout
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    stack<int> stk;
    vector<int> elem(n, -1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!stk.empty() && arr[stk.top()] <= arr[i])
        {
            stk.pop();
        }
        if (!stk.empty())
        {
            elem[i] = (stk.top() + 1);
        }
        stk.push(i);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int num;
        cin >> num;
        cout << elem[num - 1] << " ";
    }
    return 0;
}