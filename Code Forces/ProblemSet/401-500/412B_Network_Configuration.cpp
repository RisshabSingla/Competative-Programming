#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int computers;
    int students;
    cin>>computers>>students;
    vector<int> speeds;
    for(int i =0; i<computers; i++){
        int t;
        cin>>t;
        speeds.push_back(t);
    }
    sort(speeds.begin(), speeds.end());
    int index = computers-students;
    cout<<speeds[index]<<endl;
    return 0;
}