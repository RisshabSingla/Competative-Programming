#include<iostream>

using namespace std;

int main()
{
    double a;
    cin>>a;
    double total = 0;
    for(int i = 0; i<a; i++){
        int t;
        cin>>t;
        total+=t;
    }

    double per = total/a;
    cout<<per<<endl;

    return 0;
}
