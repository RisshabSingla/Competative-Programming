#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<cmath>
#include<set>
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
        int arr[n];
        for(int i = 0; i<n; i++){
            cin>>arr[i];
        }
        int left = 0;
        int right = n-1;
        set<int> div;
        set<int>::iterator itr;
        // cout<<"Here"<<endl;
        while(left<right){
            int smaller = min(arr[left] , arr[right]);
            for(int i =1; i<smaller; i++){
                if(arr[left]% i == arr[right]% i){
                    div.insert(i);
                }
            }

            for( itr = div.begin(); itr!= div.end(); itr++){
                if(arr[left] % *itr != arr[right]){
                    div.erase(itr);
                }
            }
            left++;
            right--;
        }

        for(itr = div.begin(); itr!= div.end(); itr++){
            cout<<*itr<<" ";
        }
        cout<<endl;
    }
    return 0;
}
