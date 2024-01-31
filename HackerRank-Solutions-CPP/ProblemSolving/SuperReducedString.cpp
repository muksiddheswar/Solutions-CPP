#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'superReducedString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string superReducedString(string s) 
{
    string result = s;
    int changed = 1;

    while (changed > 0)
    {
        changed = 0;
        int i = 0;
        int length = result.size();
        while(i < (length - 1) )
        {
            if (result[i] == result[i+1])
            {
                changed = 1;
                result.erase(result.begin()+i);
                result.erase(result.begin()+i);
                break;
            }

            else
            {
                // result += s[i];
                i++;
            }
        }
    } 
    
    if ( !result.size())
        result = "Empty String";
    return result;
}

int main()
{
    string s;
    getline(cin, s);
    string result = superReducedString(s);
    cout << result << "\n";
    return 0;
}
