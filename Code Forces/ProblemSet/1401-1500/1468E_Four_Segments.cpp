#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
    int cases;
    cin>>cases;
    while(cases--){
        vector<int> sides;
        for(int i = 0; i<4; i++){
            int t ;
            cin>>t;
            sides.push_back(t);
        }
        sort(sides.begin(), sides.end());
        int area = sides[0]* sides[2];
        cout<<area<<endl;
    }
    return 0;
}
