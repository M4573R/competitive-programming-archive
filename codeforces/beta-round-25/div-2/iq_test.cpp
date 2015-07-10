#include <iostream>
#include <vector>

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

    vector<unsigned int> odd;
    vector<unsigned int> even;

    for (unsigned int i {1}; i <= numbers; ++i)
    {
        unsigned int number;
        cin >> number;

        if (number % 2)
        {
            odd.push_back(i);
        }
        else
        {
            even.push_back(i);
        }
    }

    cout << (odd.size() == 1 ? odd.front() : even.front()) << '\n';

    return 0;
}
