#include <bits/stdc++.h>

using namespace std;

string isValid(string s) {
    unordered_map<char, int> al_map ;
    for (auto i = 0; i < s.size(); i++)
    {
        if(al_map.count(s[i]) > 0)
            al_map[s[i]] = al_map[s[i]] + 1;
        else
            al_map[s[i]] = 1;
    }

    for (auto i = al_map.begin() ; i != al_map.end(); i ++)
    {
        cout << i->first << " " << i->second << endl;
    }

    int in_valid = 0;
    int f_num = al_map.begin()->second; 
    int f_count = 1;
    int s_num = -1;
    int s_count = 0;
    // int removed = 0;

    for (auto i = next(al_map.begin()) ; i != al_map.end(); i ++)
    {
        if ((i->second == f_num) & (s_count < 2))
            f_count ++;

        else if (s_num == -1) 
        {
            s_num = i->second;
            s_count += 1;
        }

        else if ((i->second == s_num) & (f_count < 2))
            s_count ++;
        
        else
        {
            in_valid = 1;
            break;
        }
        
    }

    if ((!in_valid) & (s_count > 0))
    {
        if (!(abs(f_num - s_num) < 2))
            in_valid = 1;
    }    

    if (!in_valid)
        return "YES";
    else
        return "NO";
}


int main()
{
    string s;
    getline(cin, s);
    string result = isValid(s);
    cout << result << "\n";
    getline(cin, s);


    return 0;
}
