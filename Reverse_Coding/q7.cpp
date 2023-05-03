
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <limits>
using namespace std;
int main()
{
    int t;
    cin >> t;
    bool overflow = false;
    for (int i = 0; i < t; i++)
    {
        
        long long n;
        cin >> n;
        long long ans = ((n * n) + n + 2) / 2;
        if (ans > 10412767 || overflow)
        {
            // overflow = true;
            ans = INT_MIN;
        }
        cout<<ans<<endl;
        
    }
}


// #include <iostream>

// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     int term = 1;
//     int diff = 1;
//     for (int i = 2; i <= n; i++) {
//         term += diff;
//         diff++;
//     }
//     cout << term << endl;
//     return 0;
// }