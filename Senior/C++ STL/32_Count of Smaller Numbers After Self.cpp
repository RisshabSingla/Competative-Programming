#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int mod = 1000000007;

class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<int> elem;
        elem.push_back(nums[n - 1]);
        for (int i = n - 2; i >= 0; i--)
        {
            auto itr = lower_bound(elem.begin(), elem.end(), nums[i]);
            if (itr == elem.end())
            {
                ans[i] = elem.size();
                // cout<<"end\n";
            }
            else
            {
                ans[i] = itr - elem.begin();
                // cout<<*itr<<"\n";
            }
            elem.insert(itr, nums[i]);
            // itr--;

            // for(auto i: elem){
            //     cout<<i<<" ";
            // }
            // cout<<"\n";
        }
        return ans;
    }
};