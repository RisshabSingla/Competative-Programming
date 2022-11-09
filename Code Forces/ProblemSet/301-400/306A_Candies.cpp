#include<iostream>

using namespace std;

int main()
{
    int candies;
    int friends;
    cin>>candies>>friends;

    for(int i = 0; i<friends; i++){
        int total = candies+i;
        int rem = total% friends;
        if(!rem){
            int all = total/friends;
            for(int j = 0; j<(friends-i); j++){
                cout<<all<<" ";
            }
            all--;
            for(int j = friends - i; j<friends; j++){
                cout<<all<<" ";
            }
        }
    }
    return 0;
}
