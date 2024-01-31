#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int reverse_integer(int num)
{
    int rev_num = 0;
    while(num > 0)
    {
        rev_num = (rev_num * 10) + (num % 10);
        num /= 10;
    }
    return rev_num;
}

int beautifulDays(int i, int j, int k) {
    int beautiful_days = 0;
    int rev_num;
    for (int num = i; num <= j; num++)
    {
        rev_num = reverse_integer(num);
        if (!(abs(rev_num - num) % k))
            beautiful_days ++;
    }
    return beautiful_days;
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);
    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));
    int i = stoi(first_multiple_input[0]);
    int j = stoi(first_multiple_input[1]);
    int k = stoi(first_multiple_input[2]);
    int result = beautifulDays(i, j, k);
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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
