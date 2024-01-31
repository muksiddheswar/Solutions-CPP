#include <bits/stdc++.h>
# include <iostream>
using namespace std;

/*
 * Complete the 'camelcase' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int camelcase(string s) {
    int word = 1;
    int i;
    for(i = 0; i<(s.size() -1); i ++)
    {
        if (isupper(s[i]))
            break;
    }

    for (; i < (s.size() - 1); i++)
    {
        if (isupper(s[i]))
            word += 1; 
    }
    return word;
}

int main()
{
    string s;
    getline(cin, s);

    int result = camelcase(s);

    cout << result << "\n";

    return 0;
}
