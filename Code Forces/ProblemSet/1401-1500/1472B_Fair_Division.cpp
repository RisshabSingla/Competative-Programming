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
        int total;
        cin >> total;
        vector<int> inputs;
        for (int i = 0; i < total; i++)
        {
            int weight;
            cin>>weight;
            inputs.push_back(weight);
        }

        sort(inputs.begin(), inputs.end(),greater<int>());
        int alice = 0;
        int bob = 0;
        for(int i = 0; i<total; i++){
            if(alice > bob){
                bob+=inputs[i];
            }else{
                alice+=inputs[i];
            }
        }

        if(alice== bob){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
