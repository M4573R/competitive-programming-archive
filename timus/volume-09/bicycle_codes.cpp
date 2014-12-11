#include <iostream>
#include <string>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    string first_combination;
    string second_combination;

    cin >> first_combination >> second_combination;

    int first_combination_day  {stoi(first_combination)  + 1};
    int second_combination_day {stoi(second_combination) + 1};

    if (first_combination_day % 2 != 0 || second_combination_day % 2 == 0)
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }

    cout << '\n';

    return 0;
}
