#include <iostream>
#include <map>

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

    unsigned int people;
    cin >> people;

    map<unsigned int, unsigned int> frequencies;
    map<unsigned int, unsigned int> indices;

    for (unsigned int i {0}; i < people; ++i)
    {
        unsigned int roll;
        cin >> roll;

        ++frequencies[roll];
        indices[roll] = i + 1;
    }

    unsigned int winner {0};

    for (const auto& frequency : frequencies)
    {
        if (frequency.second == 1)
        {
            winner = frequency.first;
        }
    }

    if (winner)
    {
        cout << indices[winner] << '\n';
    }
    else
    {
        cout << "none\n";
    }

    return 0;
}
