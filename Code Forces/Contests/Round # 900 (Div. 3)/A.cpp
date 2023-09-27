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

bool calcAns(vector<int> &arr, int k, int n)
{
    bool present = false;
    for(auto i: arr){
        if(i == k){
            present = true;
            return true;
        }
    }
    return false;


    // for (int i = 0; i < n; i++)
    // {
    //     unordered_map<int, int> freq;
    //     for (int j = 0; j <= i; j++)
    //     {
    //         freq[arr[j]]++;
    //     }
    //     int max_freq = 0;
    //     int elem;
    //     for (auto i : freq)
    //     {
    //         if (i.second > max_freq)
    //         {
    //             max_freq = i.second;
    //             elem = i.first;
    //         }
    //     }
    //     if (elem == k)
    //     {
    //         return true;
    //     }
    // }
    // return false;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int n;
        int k;
        cin >> n >> k;
        vector<int> arr(n);
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] == k)
            {
                found = true;
            }
        }
        if (!found)
        {
            cout << "NO" << endl;
            continue;
        }
        if (calcAns(arr, k, n))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
