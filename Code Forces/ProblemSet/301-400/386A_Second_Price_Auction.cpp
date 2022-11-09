#include<iostream>

using namespace std;

int main()
{
    int people;
    cin>>people;
    int maximum = -1;
    int secondmax = -1;
    int indexmax = -1;
    for(int i =0; i<people; i++){
        int t;
        cin>>t;
        if(t>maximum){
            secondmax = maximum;
            maximum = t;
            indexmax = i;
        }
        if(t>secondmax && t<maximum){
            secondmax = t;
        }
    }
    cout<< indexmax+1<<" "<< secondmax<<endl;

    return 0;
}