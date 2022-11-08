#include <iostream>

using namespace std;

int main()
{
    int distance;
    cin >> distance;
    int steps = 0;

    while(distance != 0){
        if(distance == 1 || distance == 2 || distance == 3 || distance == 4 || distance == 5){
            steps++;
            cout<<steps<<endl;
            return 0;
        }
        distance -= 5;
        steps++;
    }

    return 0;
}
