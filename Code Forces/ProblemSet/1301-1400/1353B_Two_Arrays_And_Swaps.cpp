#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int length;
        int swaps;
        cin >> length >> swaps;
        vector<int> a;
        vector<int> b;
        for (int i = 0; i < length; i++)
        {
            int t;
            cin >> t;
            a.push_back(t);
        }
        for (int i = 0; i < length; i++)
        {
            int t;
            cin >> t;
            b.push_back(t);
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int aIndex = 0;
        int bIndex = length - 1;
        while (swaps-- && a[aIndex] < b[bIndex])
        {
            int temp = a[aIndex];
            a[aIndex] = b[bIndex];
            b[bIndex] = temp;
            aIndex++;
            bIndex--;
        }
        int sum = 0;
        for (int i = 0; i < length; i++)
        {
            sum += a[i];
        }
        cout << sum << endl;
    }
    return 0;
}
