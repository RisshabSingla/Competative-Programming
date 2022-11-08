// #include <iostream>
// #include <vector>
// #include <climits>

// using namespace std;

// int min_blessing(vector<unsigned int> blessing)
// {
//     unsigned int minimum = UINT_MAX;
//     int index;
//     for (int i = 0; i < blessing.size(); i++)
//     {
//         if (blessing[i] < minimum)
//         {
//             index = i;
//             minimum = blessing[i];
//         }
//     }
//     return index;
// }
//
// int main()
// {
//     int cases;
//     cin >> cases;
//     while (cases--)
//     {
//         int monsters;
//         cin >> monsters;
//         vector<unsigned int> health(monsters);
//         vector<unsigned int> blessing(monsters);
//         for (int i = 0; i < monsters; i++)
//         {
//             cin >> health[i];
//         }
//         for (int i = 0; i < monsters; i++)
//         {
//             cin >> blessing[i];
//         }
//         unsigned int time = 0;
//         while (health.size() != 0)
//         {
//             int min_blessing_index = min_blessing(blessing);
//             unsigned int addHealth = blessing[min_blessing_index];
//             time += health[min_blessing_index];
//
//             if (min_blessing_index - 1 > -1 && min_blessing_index + 1 < health.size())
//             {
//               // cout<<"both true"<<endl;
//                 health[min_blessing_index - 1] += addHealth;
//                 health[min_blessing_index + 1] += addHealth;
//                 health.erase(health.begin() + min_blessing_index);
//                 blessing.erase(blessing.begin() + min_blessing_index);
//                 continue;
//             }
//
//             if(min_blessing_index + 1 == health.size()){
//               // cout<<"last index"<<endl;
//                 health[min_blessing_index - 1] += addHealth;
//                 health.erase(health.begin() + min_blessing_index);
//                 blessing.erase(blessing.begin() + min_blessing_index);
//                 continue;
//             }
//
//             if(min_blessing_index - 1 == -1 ){
//               // cout<<"zero index"<<endl;
//                 health[min_blessing_index +1] += addHealth;
//                 health.erase(health.begin() + min_blessing_index);
//                 blessing.erase(blessing.begin() + min_blessing_index);
//                 continue;
//             }
//         }
//         cout<<time<<'\n';
//     }
//     return 0;
// }


#include<iostream>

using namespace std;

int main()
{
    int cases;
    cin>>cases;
    while(cases--){
        int monsters;
        cin>>monsters;
        long long int total_health = 0;
        int max_blessing = 0;
        for(int i = 0; i<monsters; i++){
            int tmp;
            cin>>tmp;
            total_health +=tmp;
        }

        for(int i = 0; i<monsters; i++){
            int tmp;
            cin>>tmp;
            total_health +=tmp;
            max_blessing = max(max_blessing, tmp);
        }
        cout<<total_health - max_blessing<<endl;
    }

    return 0;
}
