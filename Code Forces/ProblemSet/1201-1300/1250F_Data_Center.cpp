#include<iostream>
#include<cmath>
#include <climits>
using namespace std;

int main()
{
    int area;
    cin>>area;
    // double sroot = sqrt(area);
    // int length;
    // int breadth;
    // if(sroot - (int)sroot!=0){
    //     if(area%2 != 0){
    //         length =1;
    //         breadth = area;
    //     }else{
    //         length = area/2;
    //         breadth = area/length;
    //     }
    // }else{
    //     length = sroot;
    //     breadth = sroot;
    // }
    //
    // int perimeter = 2*(length+ breadth);
    // cout<<perimeter<<endl;

    int length;
    int breadth;
    int min_perimeter = INT_MAX;
    for(int i = 1; i<= sqrt(area); i++){
      if(area% i ==0){
        length = i;
        breadth = area/i;
      }
      int perimeter = 2*(length+ breadth);
      if(perimeter <min_perimeter)
        min_perimeter = perimeter;
    }
    cout<<min_perimeter<<endl;
    return 0;
}
