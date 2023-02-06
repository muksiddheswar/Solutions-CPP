#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

vector<tuple<int, int>> get_children(int i, int j, int n, int a, int b)
{
    vector<tuple<int, int>> children;
    tuple<int, int> t;
    vector<tuple<int, int>>::iterator it;
    
    t = {(i + a), (j + b)};
    // if ( 1 <= get<0>(t))
    if (( 1 <= get<0>(t)) & (get<0>(t) <= n) & (1 <= get<1>(t)) & (get<0>(t) <= n))
        children.push_back(t);

    t = {(i + a), (j - b)};
    if (( 1 <= get<0>(t)) & (get<0>(t) <= n) & (1 <= get<1>(t)) & (get<0>(t) <= n))
    {
        it = find(children.begin(), children.end(), t);
        if (it == children.end())
            children.push_back(t);
    }

    t = {(i - a), (j - b)};
    if (( 1 <= get<0>(t)) & (get<0>(t) <= n) & (1 <= get<1>(t)) & (get<0>(t) <= n))
    {

        it = find(children.begin(), children.end(), t);
        if (it == children.end())
            children.push_back(t);
    }

    t = {(i - a), (j + b)};
    if (( 1 <= get<0>(t)) & (get<0>(t) <= n) & (1 <= get<1>(t)) & (get<0>(t) <= n))
    {    
        it = find(children.begin(), children.end(), t);
        if (it == children.end())
            children.push_back(t);
    }

    for (auto i = children.begin(); i< children.end(); i++)
        cout << get<0>(*i) << " "  << get<1>(*i) << endl;

    return children;
}

int dfs_chessboard(int n, int a, int b)
{
    vector<tuple<int, int>> visited;
    vector<tuple<int, int, int>> to_visit;
    // vector<tuple<int, int, int>> visited;
    vector<tuple<int, int>> children;
    tuple<int, int, int> present_node;
    tuple<int, int> child;
    tuple<int, int> final_node = {n, n};

    to_visit.push_back({1, 1, 0});
    int shortest_path = -1;

    while (!to_visit.empty())
    {
        present_node = to_visit[0];
        tuple<int, int> temp = {get<0>(present_node), get<1>(present_node)};
        visited.push_back(temp);

        cout << endl << "Present Node: " <<get<0>(present_node) << " " << get<1>(present_node) << endl;
        to_visit.erase(to_visit.begin());
        children = get_children(get<0>(present_node), get<1>(present_node), n, a, b);
        for (int i = 0; i <children.size(); i++)
        {
            child = children[i];
            cout << "Child: "<<get<0>(child) << " "  << get<1>(child) << endl;
            if (child == final_node)
                {
                    if (shortest_path > get<2>(present_node) + 1)
                        shortest_path = get<2>(present_node) + 1;

                    continue;
                }

            if (find(visited.begin(), visited.end(), child) == visited.end())
                {
                    if (find(to_visit.begin(), to_visit.end(), child) == to_visit.end())
                        to_visit.insert(to_visit.begin(), {get<0>(child), get<1>(child), (get<2>(present_node) + 1)});
                }
        }

        cout << "Visited: " << endl;
        for (auto i = visited.begin(); i< visited.end(); i++)
            cout << get<0>(*i) << " "  << get<1>(*i) << endl;

        cout << " To Visit: " << endl;
        for (auto i = to_visit.begin(); i< to_visit.end(); i++)
            cout << get<0>(*i) << " "  << get<1>(*i) << endl;


    }
    return shortest_path;
}

vector<vector<int>> knightlOnAChessboard(int n) {
    vector<vector<int>> res;
    int i, j, steps;
    for (i = 1; i < n; i++)
    {
        for (j = 1; j < n; j++)
        {
            steps = dfs_chessboard(n, i, j);
            res[i][j] = steps;
        }
    }
    return res;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> result = knightlOnAChessboard(n);

    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result[i].size(); j++) {
            cout << result[i][j];

            if (j != result[i].size() - 1) {
                cout << " ";
            }
        }

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

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
