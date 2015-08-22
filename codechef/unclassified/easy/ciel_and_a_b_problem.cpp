#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int left;
    unsigned int right;

    cin >> left >> right;

    unsigned int correct_answer = left - right;

    if (correct_answer % 10 == 9)
    {
        cout << correct_answer - 1 << '\n';
    }
    else
    {
        cout << correct_answer + 1 << '\n';
    }

    return 0;
}
