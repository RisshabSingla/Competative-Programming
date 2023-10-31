#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int findLength(vector<int> &arr, int start, int k, int n)
{
    int num = arr[start];
    int len = 0;
    for (int i = start; i < n; i++)
    {
        if (num + k >= arr[i])
        {
            len++;
            num = arr[i];
        }
        else
        {
            break;
        }
    }
    return len;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        // n^2
        // int min_deletions = n;
        // for (int i = 0; i < n; i++)
        // {
        //     int possible = n - i;
        //     if (i > min_deletions)
        //     {
        //         break;
        //     }
        //     int len = findLength(arr, i, k, n);
        //     // cout << "Start is: " << i << " len is: " << len << endl;
        //     int del = n - len;
        //     min_deletions = min(del, min_deletions);
        //     if (min_deletions == 0)
        //     {
        //         break;
        //     }
        // }
        // cout << min_deletions << endl;

        vector<int> max_length(n, 1);
        int max_len = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] + k >= arr[i + 1])
            {
                max_length[i] = max_length[i + 1] + 1;
                max_len = max(max_len, max_length[i]);
            }
        }
        cout << n - max_len << endl;
    }
    return 0;
}
