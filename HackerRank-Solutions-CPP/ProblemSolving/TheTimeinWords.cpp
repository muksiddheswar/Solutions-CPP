#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


string timeInWords(int h, int m) 
{
    string result;
    string minutes[] = {
        "o' clock",
        "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine", "ten",
        "eleven", "twelve", "thirteen", "fourteen",
        "quarter",
        "sixteen", "seventeen", "eightteen", "nineteen",
        "twenty",
        "twenty one", "twenty two", "twenty three", "twenty four", "twenty five",
        "twenty six", "twenty seven", "twenty eight", "twenty nine",
        "half past"
    };

    int nxt = h+1;
    string hour = minutes[h];
    string nextHour;       
    if (nxt>12)
        nextHour=minutes[1];            
    else 
        nextHour = minutes[nxt];  
    
    if (m==0)
        result = hour + " " + minutes[m];
    else if (m==15)
        result = minutes[m] + " past " + hour;
    else if (m==45)
        result = minutes[15] + " to " + nextHour;
    else if (m==30)
        result = minutes[m] + " " + hour;
    else if (m<30) 
    {
        if (m==1)
            result = minutes[1] + " minute past " + hour;
        else
            result = minutes[m] + " minutes past " + hour;
    } 
    else 
    {
        if (m==59)
            result = minutes[1] + " minute to " + nextHour;
        else
            result = minutes[60-m] + " minutes to " + nextHour;
    }        
    return result;
}

int main()
{
    string h_temp;
    getline(cin, h_temp);
    int h = stoi(ltrim(rtrim(h_temp)));
    string m_temp;
    getline(cin, m_temp);
    int m = stoi(ltrim(rtrim(m_temp)));
    string result = timeInWords(h, m);
    cout << result << "\n";
    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
