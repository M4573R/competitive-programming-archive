#include <cstdlib>
#include <iostream>

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

    unsigned int cards;
    unsigned int limit;

    cin >> cards >> limit;

    int sum {0};

    for (unsigned int i {0}; i < cards; ++i)
    {
        int card;
        cin >> card;

        sum += card;
    }

    cout << (abs(sum) + limit - 1) / limit << '\n';

    return 0;
}
