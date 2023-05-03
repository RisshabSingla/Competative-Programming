#include<iostream>

using namespace std;

int main()
{
    int total;
    int initalPos;
    cin>>total>>initalPos;
    string str;
    cin>>str;
    int left = initalPos -1;
    int right = total - initalPos;
    if(right<left){
        for(int i =0; i<right; i++){
            cout<<"RIGHT"<<endl;
        }
        for(int i = total-1; i>-1; i--){
            cout<<"PRINT "<<str[i]<<endl;
            if(i !=0){
                cout<<"LEFT"<<endl;
            }
        }
    }else if(right>left){
        for(int i =0; i<left; i++){
            cout<<"LEFT"<<endl;
        }

        for(int i = 0; i<total; i++){
            cout<<"PRINT "<<str[i]<<endl;
            
            if(i!= total-1){
                cout<<"RIGHT"<<endl;
            }
        }
    }else{
        for(int i =0; i<left; i++){
            cout<<"LEFT"<<endl;
        }

        for(int i = 0; i<total; i++){
            cout<<"PRINT "<<str[i]<<endl;
            
            if(i!= total-1){
                cout<<"RIGHT"<<endl;
            }
        }
    }
    return 0;
}