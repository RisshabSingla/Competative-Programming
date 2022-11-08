#include <iostream>

using namespace std;

int main()
{
    int cases;
    cin>>cases;

    while (cases--)
    {
        int number;
        int length;
        cin >> number >> length;
        string arr[number];

        for (int i = 0; i < number; i++)
        {
          // cout<<"Enter "<<i<<" string"<<endl;
            cin >> arr[i];
        }
        // cout<<"Here"<<endl;

        int min_cost = INT_MAX;
        for (int i = 0; i < number; i++)
        {
            string a = arr[i];
            int min_cst = INT_MAX;
            for (int j = i + 1; j < number; j++)
            {
                int cst = 0;
                string b = arr[j];
                for (int k = 0; k < length; k++)
                {
                    int diff_a = a[k] - '0';
                    int diff_b = b[k] - '0';
                    int diff = abs(diff_a - diff_b);
                    cst += diff;
                }
                min_cst = min(min_cst, cst);
            }
            min_cost = min(min_cost, min_cst);
        }
        cout<<min_cost<<endl;
    }
    return 0;
}
