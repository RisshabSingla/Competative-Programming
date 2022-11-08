#include<iostream>

using namespace std;

int main()
{
    int order;
    cin>>order;
    int sum = 0;
    int middleRow = (order-1)/2;
    int middleColumn = (order-1)/2;
    int centre;
    for(int i = 0; i<order; i++){
        for(int j = 0; j<order; j++){
            int element;
            cin>>element;
            if(i == middleRow && j == middleColumn){
                centre = element;
            }
            if(i == j){
                sum+=element;
            }
            if(i == (abs(order-j)-1)){
                sum+=element;
            }
            if(i == middleRow){
                sum+=element;
            }
            if(j == middleColumn){
                sum+=element;
            }

        }
    }

    cout<<(sum - 3*centre)<<endl;
    return 0;
}
