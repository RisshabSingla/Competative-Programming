#include <iostream>

using namespace std;

int main()
{
    string word;
    cin >> word;

    int lower_case = 0;
    int upper_case = 0;

    for (int i = 0; word[i] != '\0'; i++)
    {
        char ch = word[i];
        if (islower(ch))
        {
            lower_case++;
        }
        else
        {
            upper_case++;
        }
    }

    if (lower_case < upper_case)
    {
        for (int i = 0; word[i] != '\0'; i++)
        {
            char ch = word[i];
            if (islower(ch))
            {
                word[i] = toupper(ch);
            }
        }
    }else if(lower_case > upper_case){
        for (int i = 0; word[i] != '\0'; i++)
        {
            char ch = word[i];
            if (isupper(ch))
            {
                word[i] = tolower(ch);
            }
        }
    }
    else{
        for (int i = 0; word[i] != '\0'; i++)
        {
            char ch = word[i];
            if (isupper(ch))
            {
                word[i] = tolower(ch);
            }
        }
    }
    cout<<word<<endl;

    return 0;
}
