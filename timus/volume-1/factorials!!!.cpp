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

    int n;
    cin >> n;

    string exclamation_marks;
    cin >> exclamation_marks;

    int expression_value {1};

    for (int i {n}; i > 0; i -= exclamation_marks.size())
    {
        expression_value *= i;
    }

    cout << expression_value;

    return 0;
}
