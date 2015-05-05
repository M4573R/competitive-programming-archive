#include <iostream>
#include <vector>

using namespace std;

const unsigned int modulo = 10000007;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test = 1; test <= test_cases; ++test)
    {
        vector<unsigned int> sequence(6);

        for (int i = 0; i < 6; ++i)
        {
            cin >> sequence[i];
            sequence[i] %= modulo;
        }

        unsigned int index;
        cin >> index;

        sequence.resize(index + 1);

        for (unsigned int i = 6; i <= index; ++i)
        {
            for (unsigned int j = 1; j <= 6; ++j)
            {
                sequence[i] = (sequence[i] + sequence[i - j]) % modulo;
            }
        }

        cout << "Case " << test << ": " << sequence[index] % modulo << '\n';
    }

    return 0;
}
