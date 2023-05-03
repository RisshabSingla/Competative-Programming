#include <iostream>
#include <vector>
using namespace std;

void fun(string str)
{
    int n = str.size();
    vector<int> arr;
    for (int i = 0; i < n; i++) 
    {
        char ch = str[i];
        if(ch >= 'a' && ch <='z')
            arr.push_back(0);
        else
            arr.push_back(-1);
    }
    cout<<str<<"\n";
    cout<<str<<": ";
    cout<<"[";
    cout<<arr[0];
    for (int i = 1; i < arr.size(); i++) {
        cout<<","<<arr[i];
    }
    cout<<"]"<<": "<<"One of the letters that you have entered contains non acceptable characters.\n";
}

int main()
{
    int t;
    cin>>t;
    vector<string> arr;
    while(t--)
    {
        string str;
        cin>>str;
        bool flag=1;
        if(str.size()>4 && str.size()<11)
        {
            string s = "";
            for(int i =0; i<str.length(); i++)
            {
                char ch = str[i];
                int a = ch;
                if(ch >= 'a' && ch <= 'z')
                {   
                    ch = ch + i;
                    s = s + ch;
                }
                
                else
                {
                    fun(str);flag=0;
                    break;
                }
                
            }
            if(flag)
            {cout<<str<<endl;
            cout<<s<<endl;}
        }
        else
            cout<<"string length is in unacceptable range.\n";
    }
}