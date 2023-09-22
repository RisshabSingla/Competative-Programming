#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<cmath>

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
        int digits;
        cin>>digits;
        vector<int> numbers(digits);
        for(int i = 0; i<digits; i++){
            cin>>numbers[i];
        }
        sort(numbers.begin(), numbers.end());
        numbers[0]++;
        int ans = 1;
        for(int i = 0; i<digits; i++){
            ans*= numbers[i];
        }
        cout<<ans<<endl;
        // int smallest = INT_MAX;
        // int largest = INT_MIN;
        // int product = 1;
        // for(int i = 0; i<digits; i++){
        //     int t;
        //     cin>>t;
        //     if(t == 0){
        //         if(smallest!= 0){
        //             smallest = 0;
        //         }else{
        //             cout<<0<<endl;
        //             continue;
        //         }
        //     }else{
        //         product*= t;
        //     smallest = min(smallest, t);
        //     largest = max(largest, t);
        //     }  
        // }
        // if(smallest == 0){
        //     smallest = 1;
        //     cout<<product<<endl;
        // }else{
        //     int sm = (product/largest)*(largest+1);
        // int la = (product/smallest)*(smallest+1);
        // if(sm>la){
        //     cout<<sm<<endl;
        // }else{
        //     cout<<la<<endl;
        // }
        // }
        
    }
    return 0;
}
