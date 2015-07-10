#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned long long read_sum(unsigned int terms)
{
    unsigned long long sum {0};

    for (unsigned int i {0}; i < terms; ++i)
    {
        unsigned int term;
        cin >> term;

        sum += term;
    }

    return sum;
}

int main()
{
    use_io_optimizations();

    unsigned int errors;
    cin >> errors;

    unsigned long long first_compilation  {read_sum(errors)};
    unsigned long long second_compilation {read_sum(errors - 1)};
    unsigned long long third_compilation  {read_sum(errors - 2)};

    cout << first_compilation  - second_compilation << '\n'
         << second_compilation - third_compilation  << '\n';

    return 0;
}
