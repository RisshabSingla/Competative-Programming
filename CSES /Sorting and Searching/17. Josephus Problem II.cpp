#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

void solve(int N, int K)
{
    vector<vector<int>> arr;

    int root = sqrt(N);
    int row = 0, col = 0, count = 0;
    vector<int> vec;
    for (int i = 1; i <= N; i++)
    {
        if (count > root)
        {
            count = 0;
            arr.push_back(vec);
            vec.clear();
        }
        vec.push_back(i);
        count++;
    }
    if (!vec.empty())
        arr.push_back(vec);

    vector<int> ans;

    for (int i = 0; i < N; i++)
    {
        int j = K % (N - i);
        while (j)
        {
            if (col + j < arr[row].size())
            {
                col += j;
                j = 0;
            }
            else
            {
                j -= arr[row].size() - col;
                col = 0;
                row++;
            }
            if (row >= arr.size())
                row = 0;
        }

        while (arr[row].size() <= col)
        {
            col = 0;
            row++;
            if (row >= arr.size())
                row = 0;
        }
        ans.push_back(arr[row][col]);
        if (i != N - 1)
        {
            arr[row].erase(arr[row].begin() + col);
            while (arr[row].size() <= col)
            {
                col = 0;
                row++;
                if (row >= arr.size())
                    row = 0;
            }
        }
    }
    for (auto i : ans)
    {
        cout << i << ' ';
    }
}

int main()
{
    ll n, k;
    cin >> n >> k;
    solve(n, k);
    return 0;
}