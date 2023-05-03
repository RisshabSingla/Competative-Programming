#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;


int main()
{
    int cases;
    cin>>cases;
    while(cases--){
        int num;
        cin>>num;
        int arr[num];
        int maxStrength = -1;
        int secondStrength = -1;
        for(int i =0; i<num; i++){
            cin>>arr[i];
            if(arr[i]> maxStrength){
                secondStrength = maxStrength;
                maxStrength = arr[i];
            }else if(arr[i]> secondStrength){
                secondStrength = arr[i];
            }

        }
        for(int i = 0; i<num; i++){
            if(arr[i] - maxStrength!= 0){
                cout<<arr[i] - maxStrength <<" ";
            }else{
                cout<<arr[i]- secondStrength<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
