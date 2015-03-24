#include <iostream>
#include <set>
#include <string>

using namespace std;

const set<string> valid_codes {"416", "647", "437"};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    string area_code;
    string local_number;

    cin >> area_code >> local_number;

    if (area_code.size()             != 3 ||
        valid_codes.count(area_code) == 0 ||
        local_number.size()          != 7)
    {
        cout << "invalid";
    }
    else if (area_code == "416")
    {
        cout << "valuable";
    }
    else
    {
        cout << "valueless";
    }

    cout << '\n';

    return 0;
}
