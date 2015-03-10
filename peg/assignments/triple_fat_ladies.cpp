#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

template <typename T>
inline
T cube(T number)
{
    return number * number * number;
}

inline
bool ends_in_888(unsigned long long number)
{
    return (number       % 10 == 8 &&
            number / 10  % 10 == 8 &&
            number / 100 % 10 == 8);
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned long long number;
        cin >> number;

        while (!ends_in_888(cube(++number)))
        { }

        cout << number << '\n';
    }

    return 0;
}
