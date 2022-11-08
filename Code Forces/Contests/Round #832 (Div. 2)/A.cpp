#include<iostream>
using namespace std;

int main()
{
    int cases;
    cin>>cases;
    while(cases--){
        int elements;
        cin>>elements;
        long long posSum = 0;
        long long negSum = 0;
        for(int i = 0; i<elements; i++){
            int t;
            cin>>t;
            if(t<0){
                negSum +=t;
            }else{
                posSum +=t;
            }
        }
        cout<< abs(posSum - abs(negSum))<<endl;
    }

    return 0;
}
