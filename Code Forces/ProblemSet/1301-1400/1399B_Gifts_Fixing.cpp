#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int length;
        cin>>length;
        int candies[length];
        int oranges[length];
        int minCandies = INT_MAX;
        int minOranges = INT_MAX;

        for (int i = 0; i < length; i++)
        {
            int t;
            cin >> t;
            if (t < minCandies)
            {
                minCandies = t;
            }
            candies[i] = t;
        }

        for (int i = 0; i < length; i++)
        {
            int t;
            cin >> t;
            if (t < minOranges)
            {
                minOranges = t;
            }
            oranges[i] = t;
        }
        // cout<<endl;
        long long opr = 0;
        for (int i = 0; i < length; i++)
        {
          // cout<<"inside "<<i<<endl;
            if(oranges[i] > minOranges && candies[i] > minCandies)
            {
              int orDiff = oranges[i] - minOranges;
              int caDiff = candies[i] - minCandies;
              int diff = min(orDiff, caDiff);
                opr+=diff;
                oranges[i]-=diff;
                candies[i]-=diff;
            }
            // cout<<"Opr is "<<opr<<endl;
            if (oranges[i] > minOranges)
            {
              int diff = oranges[i] - minOranges;
                opr+= diff;
                oranges[i]-=diff;
            }
            // cout<<"Opr is "<<opr<<endl;
            if (candies[i] > minCandies)
            {
              int diff = candies[i] - minCandies;
                opr+=diff;
                candies[i]-=diff;
            }
            // cout<<"Opr is "<<opr<<endl;
        }
        cout << opr << endl;
    }
    return 0;
}
