#include <iostream>

using namespace std;

constexpr unsigned int max_length {20};
constexpr unsigned int max_width  {20};
constexpr unsigned int max_height {20};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {1}; test <= test_cases; ++test)
    {
        unsigned int length;
        unsigned int width;
        unsigned int height;

        cin >> length >> width >> height;

        cout << "Case " << test << ": ";

        if (length <= max_length && width <= max_width && height <= max_height)
        {
            cout << "good";
        }
        else
        {
            cout << "bad";
        }

        cout << '\n';
    }

    return 0;
}
