#include <iostream>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int length;
        cin >> length;
        int oddIndex = length / 2;
        int evenIndex = length - oddIndex;
        int even = 0;
        int odd = 0;
        int swaps = 0;
        for (int i = 0; i < length; i++)
        {
            int num;
            cin >> num;
            if (num % 2 == 0){
                even++;
                if (i % 2 != 0)
                    swaps++;
            }else{
                odd++;
                if (i % 2 == 0)
                    swaps++;
            }
        }

        if (oddIndex != odd || evenIndex != even)
        {
            cout << -1 << endl;
            continue;
        }

        cout<<swaps/2<<endl;


    }
    return 0;
}
