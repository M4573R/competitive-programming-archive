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

    double       sum   {0};
    unsigned int count {0};

    for (unsigned int i {0}; i < 6; ++i)
    {
        double number;
        cin >> number;

        if (number > 0)
        {
            sum += number;
            ++count;
        }
    }

    cout << count       << " valores positivos\n"
         << sum / count << '\n';

    return 0;
}
