
#include <iostream>
#include <vector>
using namespace std;
int main()
{

    int cases;
    cin >> cases;
    while (cases--)
    {
        int in;
        vector<int> ans;
        cin >> in;
        int arr[in];
        for (int i = 0; i < in; i++)
        {
            cin >> arr[i];
        }

        if (in % 2 == 0)
        {
            for (int i = 0; i < in; i += 2)
            {
                ans.push_back(arr[i]);
            }
            int length = ans.size();

            for (int i = length - 1; i >= 0; i--)
            {
                ans.push_back(ans[i]);
            }
        }
        else
        {
            // in is odd
            // ans.push_back(arr[0]);
           for (int i = 0; i < in; i++)
                {
                    int num = arr[i];
                    if (i % 2 == 0)
                    {
                        ans.push_back(num);
                    }
                }
                for (int i = in - 1; i >= 0; i--)
                {
                    int num = arr[i];
                    if (i % 2 == 1)
                    {
                        ans.push_back(num);
                    }
                }
            
        }

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}