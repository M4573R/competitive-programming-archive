#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void read_input(unsigned int& problems,
                vector<vector<string>>& code_names,
                vector<unsigned int>& order)
{
    cin >> problems;

    code_names.resize(problems);

    for (unsigned int i {0}; i < problems; ++i)
    {
        code_names[i].resize(3);

        cin >> code_names[i][0]
            >> code_names[i][1]
            >> code_names[i][2];

        sort(code_names[i].begin(), code_names[i].end());
    }

    order.resize(problems);

    for (auto& problem_id : order)
    {
        cin >> problem_id;
        --problem_id;
    }
}

vector<string> choose_code_names(const vector<vector<string>>& code_names,
                                 const vector<unsigned int>& order)
{
    vector<string> chosen {code_names[order[0]][0]};

    for (unsigned int i {1}; i < order.size(); ++i)
    {
        for (unsigned int j {0}; j < 3; ++j)
        {
            if (chosen.back() < code_names[order[i]][j])
            {
                chosen.push_back(code_names[order[i]][j]);
                break;
            }
        }
    }

    return chosen;
}

void write_output(const vector<string>& chosen, unsigned int problems)
{
    if (chosen.size() == problems)
    {
        for (const auto& code_name : chosen)
        {
            cout << code_name << '\n';
        }
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }
}

int main()
{
    use_io_optimizations();

    unsigned int problems;
    vector<vector<string>> code_names;
    vector<unsigned int>   order;

    read_input(problems, code_names, order);
    write_output(choose_code_names(code_names, order), problems);

    return 0;
}
