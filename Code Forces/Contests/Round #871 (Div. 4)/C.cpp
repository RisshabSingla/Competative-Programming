#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<cmath>
#include<climits>

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
        int n;
        cin>>n;
        vector<pair <int,string> > arr(n);
        int both = INT_MAX;
        for(int i = 0; i<n; i++){
            cin>>arr[i].first;
            cin>>arr[i].second;
            if(arr[i].second == "11"){
                both = min(both, arr[i].first);
            }
        }
        // cout<<"Both is: "<<both<<endl;

        // first
        int first = INT_MAX;
        int second  = INT_MAX;
        for(int i = 0; i<n; i++){
            if(arr[i].second == "01"){
                second = min(second,arr[i].first);
            }
            if(arr[i].second == "10"){
                first = min(first,arr[i].first);
            }
        }
        // cout<<"first "<<first<<endl;
        // cout<<"second "<<second<<endl;


        if(both!= INT_MAX){
            if(first == INT_MAX || second == INT_MAX){
                cout<<both<<endl;
            }else if(first+second < both){
                cout<<first+second<<endl;
            }else{
                cout<<both<<endl;
            }
        }else if(both == INT_MAX){
            if(first == INT_MAX || second == INT_MAX){
                cout<<-1<<endl;
            }else{
                cout<<first+second<<endl;
            }
        }
    }
    return 0;
}
