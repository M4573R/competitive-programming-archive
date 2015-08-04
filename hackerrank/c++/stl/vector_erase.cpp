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

    unsigned int index;
    unsigned int left;
    unsigned int right;

    cin >> index >> left >> right;

    sequence.erase(sequence.cbegin() + index - 1);
    sequence.erase(sequence.cbegin() + left - 1,
                   sequence.cbegin() + right - 1);

    cout << sequence.size() << '\n';

    for (auto i = sequence.cbegin(); i != sequence.cend(); ++i)
    {
        cout << *i << " \n"[i + 1 == sequence.cend()];
    }

    return 0;
}
