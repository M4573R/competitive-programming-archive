#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool is_inverse(vector<unsigned int>& permutation)
{
    for (vector<unsigned int>::size_type i {0}; i < permutation.size(); ++i)
    {
        if (permutation[permutation[i] - 1] != i + 1)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    unsigned int permutation_size;
    cin >> permutation_size;

    while (permutation_size > 0)
    {
        vector<unsigned int> permutation(permutation_size);

        for (unsigned int i {0}; i < permutation_size; ++i)
        {
            cin >> permutation[i];
        }

        cout << (is_inverse(permutation) ? "ambiguous\n" : "not ambiguous\n");

        cin >> permutation_size;
    }

    return 0;
}
