#include <iostream>
#include <string>
#include <vector>

using namespace std;

const vector<string> months {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int month;
    cin >> month;

    cout << months[month - 1] << '\n';

    return 0;
}
