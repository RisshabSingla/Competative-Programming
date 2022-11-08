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

        if((length/2)%2 != 0){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        int totalevn = 0;
        for(int i =1; i<=length/2; i++){
            cout<<2*i<<" ";
            totalevn += 2*i;
        }
        int totalodd = 0;
        for(int i = 1; i<length/2; i++){
            cout<<(2*i-1)<<" ";
            totalodd += (2*i-1);
        }
        cout<<(totalevn - totalodd)<<endl;
    }


    return 0;
}
