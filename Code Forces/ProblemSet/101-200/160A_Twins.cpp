#include<iostream>
#include <vector>
#include<algorithm>

using namespace std;

int main()
{
    int number;
    cin>>number;
    vector<int> coins;
    int totalCoinsSum = 0;
    for(int i = 0; i<number; i++){
        int t;
        cin>>t;
        totalCoinsSum+=t;
        coins.push_back(t);
    }
    sort(coins.begin(), coins.end());
    int leftSum = totalCoinsSum;
    int mySum = 0;
    int myCoins = 0;
    for(int i = coins.size()-1; i>=0; i--){
        leftSum-=coins[i];
        mySum+=coins[i];
        myCoins++;
        if(leftSum <mySum){
            break;
        }
    }
    cout<<myCoins<<endl;
    
    return 0;
}