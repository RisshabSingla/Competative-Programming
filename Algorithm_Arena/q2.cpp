#include <iostream>
#include<algorithm>

using namespace std;


int main(){
    int cases;
    cin>>cases;
    while(cases--){
        int cycles;
        cin>>cycles;
        int height = 0;
        for(int i =0; i<cycles; i++){
            if(i%2==0){
                height+=1;
            }else{
                height = height*2;
            }
        }
        cout<<height<<endl;

    }
}