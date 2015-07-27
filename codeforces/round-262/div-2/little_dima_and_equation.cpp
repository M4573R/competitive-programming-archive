#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

long long exponentiate(long long base, unsigned int exponent)
{
    long long result {1};

    for (unsigned int i {0}; i < exponent; ++i)
    {
        result *= base;
    }

    return result;
}

unsigned int digits_sum(unsigned long long number)
{
    unsigned int sum {0};

    for (unsigned long long i {number}; i != 0; i /= 10)
    {
        sum += i % 10;
    }

    return sum;
}

bool check(long long number, unsigned int sum)
{
    return number > 0 && number < 1000000000 && digits_sum(number) == sum;
}

int main()
{
    use_io_optimizations();

    int a;
    int b;
    int c;

    cin >> a >> b >> c;

    vector<int> solutions;

    for (unsigned int i {1}; i <= 81; ++i)
    {
        long long number {b * exponentiate(i, a) + c};

        if (check(number, i))
        {
            solutions.push_back(number);
        }
    }

    cout << solutions.size() << '\n';

    for (auto i = solutions.cbegin(); i != solutions.cend(); ++i)
    {
        cout << *i << " \n"[i + 1 == solutions.cend()];
    }

    return 0;
}
