#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int numbers;
    cin >> numbers;

    unsigned int inside  {0};
    unsigned int outside {0};

    for (unsigned int i {0}; i < numbers; ++i)
    {
        int number;
        cin >> number;

        if (number >= 10 && number <= 20)
        {
            ++inside;
        }
        else
        {
            ++outside;
        }
    }

    cout << inside  << " in\n"
         << outside << " out\n";

    return 0;
}
