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

    unsigned int laptops;
    cin >> laptops;

    bool is_happy {false};

    for (unsigned int i {0}; i < laptops; ++i)
    {
        unsigned int price;
        unsigned int quality;

        cin >> price >> quality;

        if (price != quality)
        {
            is_happy = true;
        }
    }

    cout << (is_happy ? "Happy Alex" : "Poor Alex") << '\n';

    return 0;
}
