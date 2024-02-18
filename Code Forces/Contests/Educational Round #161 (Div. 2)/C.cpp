#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Type Redefenition
#define int ll
typedef long long ll;
#define double long double
#define pii pair<int, int>
#define vi vector<int>
#define mii map<int, int>
#define ADJ map<int, set<int>>
#define vpii vector<pii>

// Common Helpers
#define pb push_back
#define ed end()
#define bg begin()
#define sz size()
#define ln length()
#define all(x) x.begin(), x.end()
#define endl '\n'
#define NL cout << '\n';
#define F first
#define S second
#define disp(x)      \
    for (auto t : x) \
        cout << t << " ";
#define for0(n) for (int i = 0; i < n; i++)
#define for0j(n) for (int j = 0; j < n; j++)
#define oldfor(v) for (auto it = v.begin(); it != v.end(); ++it)
#define SS << ' ' <<
#define arrin(a, n) \
    vi a(n);        \
    for0(n) { cin >> a[i]; }
#define pf(x) cout << x << endl;
#define gridin(num, n, m) \
    for0(n) { for0j(m) cin >> num[i][j]; }
#define dispgrid(num, n, m)                \
    for0(n)                                \
    {                                      \
        for0j(m) cout << num[i][j] << ' '; \
        cout << endl;                      \
    }

// Input Output Helpers
#define tks(x) \
    string x;  \
    cin >> x;
#define tk(a) \
    int a;    \
    cin >> a;
#define tk2(a, b) tk(a) tk(b)
#define tk3(a, b, c) tk2(a, b) tk(c)
#define tk4(a, b, c, d) tk2(a, b) tk2(c, d)
#define tk5(a, b, c, d, e) tk4(a, b, c, d) tk(e)
#define tk6(a, b, c, d, e, f) tk3(a, b, c) tk3(d, e, f)
#define tk7(a, b, c, d, e, f, g) tk6(a, b, c, d, e, f) tk(g)
#define tk8(a, b, c, d, e, f, g, h) tk7(a, b, c, d, e, f, g) tk(h)
#define addEdge(adj)            \
    tk2(u, v) adj[u].insert(v); \
    adj[v].insert(u);
#define test tk(tt) while (tt--)

// Common Responses
#define YES cout << "YES" << endl;
#define Yes cout << "Yes" << endl;
#define NO cout << "NO" << endl;
#define No cout << "No" << endl;
#define yes cout << "yes" << endl;
#define no cout << "no" << endl;
#define accuracy chrono::steady_clock::now().time_since_epoch().count()

// Constants
const int MOD = 1000000007;
const int N = 100000;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases;
    cin >> cases;
    while (cases--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        vector<int> left(n);
        vector<int> right(n);

        for (int i = 0; i < n - 1; i++)
        {
            right[i + 1] = right[i];
            if (i == 0 || arr[i] - arr[i - 1] > arr[i + 1] - arr[i])
            {
                right[i + 1]++;
            }
            else
            {
                right[i + 1] += (arr[i + 1] - arr[i]);
            }
        }

        for (int i = n - 1; i > 0; i--)
        {
            left[i - 1] = left[i];
            if (i == n - 1 || arr[i] - arr[i - 1] < arr[i + 1] - arr[i])
            {
                left[i - 1]++;
            }
            else
            {
                left[i - 1] += (arr[i] - arr[i - 1]);
            }
        }

        int q;
        cin >> q;
        for (int i = 0; i < q; i++)
        {
            int start, end;
            cin >> start >> end;
            start--;
            end--;
            if (start < end)
            {
                cout << right[end] - right[start] << "\n";
            }
            else
            {
                cout << left[end] - left[start] << "\n";
            }
        }
    }
    return 0;
}
