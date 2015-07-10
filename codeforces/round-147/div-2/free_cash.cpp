#include <algorithm>
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

    unsigned int visitors;
    cin >> visitors;

    vector<unsigned int> count(23 * 60 + 60);

    for (unsigned int i {0}; i < visitors; ++i)
    {
        unsigned int hours;
        unsigned int minutes;

        cin >> hours >> minutes;

        ++count[hours * 60 + minutes];
    }

    cout << *max_element(count.cbegin(), count.cend()) << '\n';

    return 0;
}
