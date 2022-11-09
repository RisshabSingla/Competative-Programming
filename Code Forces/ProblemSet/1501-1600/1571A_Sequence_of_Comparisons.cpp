#include<iostream>

using namespace std;

int main()
{
    int cases;
    cin>>cases;
    while(cases--){
        string str;
        cin>>str;
        int equal = 0;
        int greater = 0;
        int less = 0;
        for(int i =0 ; i<str.length(); i++){
            char ch = str[i];
            if(ch == '='){
                equal++;
            }
            if(ch == '<'){
                greater++;
            }
            if(ch == '>'){
                less++;
            }
        }
        if(greater > 0 && less != 0 || greater!=0 && less>0){
            cout<<"?"<<endl;
        }else if(greater>0){
            cout<<"<"<<endl;
        }else if(less>0){
            cout<<">"<<endl;
        }else{
            cout<<"="<<endl;
        }
    }
    return 0;
}
