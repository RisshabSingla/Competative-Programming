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
        int trees;
        int max_amt;
        cin>>trees>>max_amt;

        vector<int> numFruits(trees,0);
        vector<int> heights(trees,0);
        for(int i = 0; i<trees; i++){
            cin>> numFruits[i];
        }

        for(int i = 0; i<trees;i++){
            cin>>heights[i];
        }


        // Contest Code
        // int left = 0;
        // int right = 0;
        // int ans = 0;
        // int curr_sum = numFruits[0];
        // while(right!= trees){
        //     while(right+1<trees &&  curr_sum + numFruits[right+1] <= max_amt && 
        //     heights[right]% heights[right+1] == 0){
        //         curr_sum+= numFruits[right+1];
        //         right++;
        //     }
        //     if(curr_sum<=max_amt){
        //         cout<<left<<" "<<right<<endl;
        //         ans = max(ans, right-left+1);
        //         left = right+1;
        //         right++;
        //         // right = left+1;
        //     }else{
        //         cout<<left<<" "<<right<<endl;
        //         curr_sum-= numFruits[left];
        //         ans = max(ans, right-left+1);
        //         left++;
        //     }
            
        //     // left = right+1;
        //     // right++;
        //     if(right >= trees){
        //         break;
        //     }
        //     // curr_sum = numFruits[right];
        // }
        // // if(curr_sum <= max_amt){
        // //     // cout<<left<<" "<<right<<endl;
        // //     ans = max(ans, right-left+1);
        // // }
        // cout<<ans<<endl;


        // After Contest

        int ans = INT_MIN;
        long long sum = 0;
        int start = 0;
        for(int end = 0; end<trees; end++){
            if(end>0 && heights[end-1] % heights[end]){
                start = end;
                sum = 0;
            }
            sum+= numFruits[end];
            while(start<= end && sum > max_amt){
                sum-=numFruits[start];
                start++;
            }
            int len = end-start+1;
            ans = max(len, ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}
