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

    unsigned int problems;
    cin >> problems;

    unsigned int implemented_problems {0};

    for (unsigned int i {0}; i < problems; ++i)
    {
        bool petya_is_sure;
        bool vasya_is_sure;
        bool tonya_is_sure;

        cin >> petya_is_sure >> vasya_is_sure >> tonya_is_sure;

        if (petya_is_sure + vasya_is_sure + tonya_is_sure > 1)
        {
            ++implemented_problems;
        }
    }

    cout << implemented_problems << '\n';

    return 0;
}
