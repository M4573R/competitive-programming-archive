#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int digits_sum(unsigned int number)
{
    unsigned int sum {0};

    for (unsigned int i {number}; i > 0; i /= 10)
    {
        sum += i % 10;
    }

    return sum;
}

int main()
{
    use_io_optimizations();

    char dash;

    unsigned int first;
    unsigned int second;
    unsigned int third;

    cin >> first >> dash >> second >> dash >> third;

    unsigned int first_sum  {digits_sum(first)};
    unsigned int second_sum {digits_sum(second)};
    unsigned int third_sum  {digits_sum(third)};

    if (first_sum == second_sum && second_sum == third_sum)
    {
        cout << "Goony!";
    }
    else
    {
        cout << "Pick up the phone!";
    }

    cout << '\n';

    return 0;
}
