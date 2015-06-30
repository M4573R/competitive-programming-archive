#include <iomanip>
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

    cout << fixed << setprecision(2);

    unsigned int sum   {0};
    unsigned int count {0};

    for (int age; cin >> age && age >= 0; )
    {
        sum += age;
        ++count;
    }

    cout << static_cast<double>(sum) / count << '\n';

    return 0;
}
