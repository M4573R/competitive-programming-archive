#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline
void fizz_fuzz(unsigned int number)
{
    if (number % 7 == 0 && number % 13 == 0)
    {
        cout << "Fizz Fuzz";
    }
    else if (number % 7 == 0)
    {
        cout << "Fizz";
    }
    else if (number % 13 == 0)
    {
        cout << "Fuzz";
    }
    else
    {
        cout << number;
    }
}

int main()
{
    use_io_optimizations();

    unsigned int rounds;
    cin >> rounds;

    unsigned int first  {1};
    unsigned int second {1};

    for (unsigned int i {0}; i < rounds; ++i)
    {
        fizz_fuzz(first);
        cout << ' ';

        fizz_fuzz(second);
        cout << '\n';

        first  += 1;
        second += 2;
    }

    return 0;
}
