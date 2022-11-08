#include <iostream>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int n;
        cin >> n;
        // if (n % 2 == 0)
        // {
        //     int swaps = n / 2;
        //     cout << swaps << endl;
        //     int length = n * 3 - 1;
        //     int start = 0;
        //     while (start < length)
        //     {
        //         int firstIndex = start + 1;
        //         int secondIndex = start + 5;
        //         cout << firstIndex << " " << secondIndex << endl;
        //         start = start + 6;
        //     }
        // }else{
        //     int swaps = (n-1)/2 + 1;
        //     cout<<swaps<<endl;
        //     int length = (n-1) * 3 - 1;
        //     int start = 0;
        //     while (start < length)
        //     {
        //         int firstIndex = start + 1;
        //         int secondIndex = start + 5;
        //         cout << firstIndex << " " << secondIndex << endl;
        //         start = start + 6;
        //     }
        //     cout<<length +2 << " "<<length+3<<endl;
        // }
        int length = 3*n-1;
        int lastIndexN = length;
        int firstIndexA = 1;
        int swaps = (n+1)/2;
        cout<<swaps<<endl;
        int count = 0;
        while(lastIndexN > 1 && firstIndexA < length && count<swaps){
          cout<<firstIndexA+1 <<" "<<lastIndexN+1<<endl;
          lastIndexN -=3;
          firstIndexA +=3;
          count++;
        }
    }
    return 0;
}
