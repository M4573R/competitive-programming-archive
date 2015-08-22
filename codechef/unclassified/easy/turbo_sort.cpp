#include <iostream>
#include <vector>

using namespace std;

constexpr unsigned int max_number = 1000001;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    vector<unsigned int> frequencies(max_number);

    unsigned int input_size;
    cin >> input_size;

    for (unsigned int i {0}; i < input_size; ++i)
    {
        unsigned int item;
        cin >> item;

        ++frequencies[item];
    }

    for (vector<unsigned int>::size_type i {0}; i < frequencies.size(); ++i)
    {
        for (unsigned int j {0}; j < frequencies[i]; ++j)
        {
            cout << i << '\n';
        }
    }

    return 0;
}
