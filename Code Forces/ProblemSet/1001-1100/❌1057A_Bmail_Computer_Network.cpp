#include <iostream>
#include <vector>

using namespace std;

class router
{
public:
    router *prev;
    int index;
    vector<router *> next;
};

int main()
{
    int number;
    cin >> number;
    int index = 1;
    router network[number];
    int t;
    cin >> t;
    network[0].prev = NULL;
    network[0].index = index;
    index++;
    for (int i = 0; i < number - 2; i++)
    {
        cin >> t;
        network[index].index = index;
        index++;
        network[t].prev = &network[t];
        // network[t-1].next.push_back()

    }

    return 0;
}