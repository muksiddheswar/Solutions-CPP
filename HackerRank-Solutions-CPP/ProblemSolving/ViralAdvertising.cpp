#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


int viralAdvertising(int n) {
    int shared = 5;
    int cumulative_likes = 0;
    int liked = 0;
    for (int day = 1; day <= n; day++)
    {
        liked = floor(shared / 2);
        cumulative_likes += liked;
        shared = liked * 3;
    }
    return cumulative_likes;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);
    int n = stoi(ltrim(rtrim(n_temp)));
    int result = viralAdvertising(n);
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
