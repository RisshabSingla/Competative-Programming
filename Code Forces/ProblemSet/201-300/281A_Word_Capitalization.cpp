#include<iostream>

using namespace std;

int main()
{
    string c;
    cin>>c;
    c[0] = char(toupper(c[0]));
    cout<<c;
    return 0;
}