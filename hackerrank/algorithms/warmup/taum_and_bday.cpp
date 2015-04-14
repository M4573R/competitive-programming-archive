#include <algorithm>
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

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned long long black_count;
        unsigned long long white_count;

        cin >> black_count >> white_count;

        unsigned long long black_price;
        unsigned long long white_price;
        unsigned long long convert_price;

        cin >> black_price >> white_price >> convert_price;

        unsigned long long price {
            black_count * min(black_price, white_price + convert_price) +
            white_count * min(white_price, black_price + convert_price)
        };

        cout << price << '\n';
    }

    return 0;
}
