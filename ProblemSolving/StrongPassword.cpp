#include <bits/stdc++.h>
// # include <iostream>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'minimumNumber' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING password
 */

int minimumNumber(int n, string password) {


    // Return the minimum number of characters to make the password strong
    int upper_case = 0;
    int lower_case = 0;
    int special_characters = 0;
    int digits = 0;
    string test = "!@#$%^&*()-+";
    int to_insert = 0;
    int min_size = 0;
    string t ;

    if (password.size() < 6)
        min_size = (6 - password.size());

    for (auto index = 0; index < password.size(); index ++)
    {
        t = password[index];
        if (isupper(password[index]))
            upper_case += 1;
        else if (islower(password[index]))
            lower_case += 1;
        else if (isdigit(password[index]))
            digits += 1;
        else if (test.find(password[index]) != string::npos)
            special_characters += 1;
    }

    if (!upper_case)
        to_insert += 1;
    if (!lower_case)
        to_insert += 1;
    if (!special_characters)
        to_insert += 1;
    if (!digits)
        to_insert += 1;

    return max(min_size, to_insert);

}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    cout << answer << "\n";

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
