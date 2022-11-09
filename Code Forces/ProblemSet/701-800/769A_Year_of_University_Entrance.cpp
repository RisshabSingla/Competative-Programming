#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int number;
    cin>>number;
    vector<int> years;
    for(int i = 0; i<number; i++){
        int elem;
        cin>>elem;
        years.push_back(elem);
    }

    sort(years.begin(), years.end());
    int middle = number/2;
    cout<<years[middle];

    return 0;
}
