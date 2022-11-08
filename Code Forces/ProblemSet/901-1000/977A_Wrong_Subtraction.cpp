#include<iostream>

using namespace std;

int main()
{
    int number;
    int times;
    cin>>number>>times;

    while(times--){
        if(number%10 == 0){
            number = number/10;
        }else{
            number-=1;
        }
    }
    cout<<number<<endl;
    return 0;
}
