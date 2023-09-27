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


void buildTree(vector<ll> &arr, vector<ll> &tree, ll start, ll end, ll node){
    if(start == end){
        tree[node] = arr[start];
        return;
    }
    ll mid = start + (end-start)/2;
    buildTree(arr, tree, start, mid, 2*node);
    buildTree(arr, tree, mid+1, end, 2*node+1);
    tree[node] = tree[2*node+1] & tree[2*node];
}

ll getValue(vector<ll> &arr, vector<ll> &tree, ll start, ll end, ll node, ll left, ll right){
    
    // completely inside
    if(start>=left && end <= right){
        return tree[node];
    }

    // completely outside
    if(end<left || start> right){
        return ((1LL<<32)-1);
    }

    // partially 
    ll mid = start +(end-start)/2;

    ll a = getValue(arr, tree, start, mid, 2*node, left, right);
    ll b = getValue(arr, tree, mid+1, end, 2*node+1, left, right);
    return a & b;
}

int main()
{
    int cases;
    cin>>cases;
    while(cases--){
        // Contest Code
        ll n;
        cin>>n;
        vector<ll> arr(n);
        for(int i = 0; i<n; i++){
            cin>>arr[i];
        }
        vector<ll> tree(4*n, LLONG_MAX);
        buildTree(arr, tree, 0, n-1,1);
        // for(int i = 0; i<4*n; i++){
        //     cout<<tree[i]<<" ";
        // }
        // cout<<endl;
        // cout<<"Tree build"<<endl;
        int q;
        cin>>q;
        while(q--){
            ll left;
            ll k;
            cin>>left>>k;
            ll index = -1;
            // Linear Search
            // for(ll i = left-1; i<n; i++){
            //     ll ans = getValue(arr, tree, 0, n-1, 1, left-1, i);
                
            //     if(ans >= k){
            //         index = i;
            //     }
            // }

            // Using binary search
            int start = left-1;
            int end = n-1;
            while(start<=end){
                int mid = start + (end-start)/2;
                int val = getValue(arr, tree, 0, n-1, 1, left-1, mid);
                if(val >= k){
                    index = mid;
                    start = mid+1;
                }else{
                    end = mid-1;
                }
            }

            if(index!=-1){
                cout<<index+1<<" ";
            }else{
                cout<<-1<<" ";
            }
        }
        cout<<endl;


        // Brute Force
        // int n;
        // cin>>n;
        // vector<int> arr(n);
        // for(int i = 0; i<n; i++){
        //     cin>>arr[i];
        // }

        // vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        // for(int i = 0; i<n; i++){
        //     int a = arr[i];
        //     for(int j = i; j<n; j++){
        //         a = a & arr[j];
        //         dp[i][j] = a;
        //     }
        // }

        // // cout<<"DP is: "<<endl;
        // // for(auto i: dp){
        // //     for(auto j: i){
        // //         cout<<j<<" ";
        // //     }
        // //     cout<<endl;
        // // }
        // // cout<<endl;

        // int q;
        // cin>>q;
        // while(q--){
        //     int left;
        //     int k;
        //     cin>>left>>k;
        //     left--;
        //     int index = -1;
        //     for(int i = 0; i<n; i++){
        //         if(dp[left][i] >= k){
        //             index = i;
        //         }
        //     }
        //     if(index!= -1){
        //         cout<<index+1<<" ";
        //     }else{
        //         cout<<-1<<" ";
        //     }
        // }
        // cout<<endl;
   
    }
    return 0;
}
