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


bool isValid(int height, vector<int> &heights, int max_water, int cols){
    int water = 0;
    for(int i = 0; i<cols; i++){
        water+= max((height-heights[i]),0);
        if(water>max_water){
            return false;
        }
    }
    if(water <= max_water){
        return true;
    }
    return false;
}

int main()
{
    int cases;
    cin>>cases;
    while(cases--){
        int cols;
        int max_water;
        cin>>cols>>max_water;
        vector<int> heights(cols, 0);
        for(int i = 0; i<cols; i++){
            cin>>heights[i];
        }

        int left = 0;
        int right = INT_MAX;
        int ans = 0;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(isValid(mid, heights,max_water, cols)){
                left = mid+1;
                ans = max(ans, mid);
            }else{
                right = mid-1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
