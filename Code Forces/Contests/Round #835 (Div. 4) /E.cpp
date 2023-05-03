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
        int length;
        cin>>length;
        ll arr[length];
        ll zeros[length];
        ll zeros_new[length];
        ll ones  = 0;
        ll zero = 0;
        for(int i =0; i<length; i++){
            cin>>arr[i];
            if(arr[i] == 0){
              zero++;
            }else{
              ones++;
            }
        }
        int count = 0;
        if(zero == 0){
            cout<<length-1<<endl;
            continue;
        }
        for(int i =length-1; i>=0; i--){
            zeros[i] = count;
            if(arr[i] == 0){
                count++;
            }
        }

        ll inversion = 0;
        // without inversion;
        for(int i = 0; i<length; i++){
            if(arr[i] == 1){
                inversion+=zeros[i];
            }
        }

        ll withinversionbegin= 0;
        // with inversion at begin;
        int index;
        for(index = 0; index<length; index++){
            if(arr[index] == 0 ){
                arr[index] =1;
                break;
            }
        }

        for(int i = index-1; i>=0; i--){
            zeros[i]--;
        }

        for(int i = 0; i<length; i++){
            if(arr[i] == 1){
                withinversionbegin+=zeros[i];
            }
        }
        arr[index] = 0;
        // with inversion end;
        int last;
        for(last = length-1; last>=0; last--){
            if(arr[last] == 1){
                arr[last] = 0;
                break;
            }
        }
        count = 0;
        for(int i =length-1; i>=0; i--){
            zeros_new[i] = count;
            if(arr[i] == 0){
                count++;
            }
        }
        ll inversionEnd = 0;
        for(int i = 0; i<length; i++){
            if(arr[i] == 1){
                inversionEnd+=zeros_new[i];
            }
        }
        // cout<<"Inversion is: "<<inversion<<endl;
        // cout<<"InversionBeign is: "<<withinversionbegin<<endl;
        // cout<<"InversionEnd is: "<<inversionEnd<<endl;

        cout<<max(inversion, max(withinversionbegin, inversionEnd))<<endl;
    }
    return 0;
}
