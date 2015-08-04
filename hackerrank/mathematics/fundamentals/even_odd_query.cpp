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

    unsigned int length;
    cin >> length;

    vector<unsigned int> sequence(length);

    for (auto& element : sequence)
    {
        cin >> element;
    }

    unsigned int queries;
    cin >> queries;

    for (unsigned int i {0}; i < queries; ++i)
    {
        unsigned int left;
        unsigned int right;

        cin >> left >> right;

        if (sequence[left - 1] % 2 || (left < right && sequence[left] == 0))
        {
            cout << "Odd\n";
        }
        else
        {
            cout << "Even\n";
        }
    }

    return 0;
}
