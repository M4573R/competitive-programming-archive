#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool is_ambiguous(const vector<unsigned int>& permutation)
{
    for (auto i = permutation.cbegin(); i != permutation.cend(); ++i)
    {
        if (permutation[permutation[*i - 1] - 1] != *i)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    use_io_optimizations();

    for (unsigned int length; cin >> length && length > 0; )
    {
        vector<unsigned int> permutation(length);

        for (auto& element : permutation)
        {
            cin >> element;
        }

        if (is_ambiguous(permutation))
        {
            cout << "ambiguous\n";
        }
        else
        {
            cout << "not ambiguous\n";
        }
    }

    return 0;
}
