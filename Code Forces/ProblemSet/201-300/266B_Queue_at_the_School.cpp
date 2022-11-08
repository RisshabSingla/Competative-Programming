#include <iostream>

using namespace std;

int main()
{
    int number;
    int time;
    cin >> number >> time;
    string arrangement;
    cin >> arrangement;

    while (time--)
    {
        // cout << "inside" << endl;
        for (int i = 1; arrangement[i] != '\0'; i++)
        {
            if (arrangement[i - 1] == 'B' && arrangement[i] == 'G')
            {
                // cout<<"Hello"<<endl;
                // cout<<"Val of i: "<<i<<endl;
                arrangement[i] = 'B';
                arrangement[i - 1] = 'G';
                // cout<<arrangement<<endl;
                i++;
            }
        }
    }
    cout << arrangement << endl;

    return 0;
}
