#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
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
        unordered_map<int,int> present;
        bool ans = true;
        int m;
        int sum;
        cin>>m>>sum;
        int maximum = -1;
        // int arr[m];
        for(int i =0; i<m; i++){
            int element;
            cin>>element;
            if(element>maximum){
                maximum = element;
            }

            if(present.count(element) > 0){
                ans = false;
            }else{
                present[element] = 1;
            }
        }
        int total = 0;
        int i;
        for( i = 1; total<sum || i<maximum; i++){
            if(present.count(i) == 0){
                total+=i;
            }
        }
        
        if(total == sum && i>=maximum && ans){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}