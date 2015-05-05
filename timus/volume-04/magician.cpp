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

    unsigned int digits_count;
    unsigned int clicks;

    cin >> digits_count >> clicks;

    vector<unsigned int> digits(digits_count);

    for (auto& digit : digits)
    {
        cin >> digit;
    }

    for (unsigned int i {clicks}; i < clicks + 10; ++i)
    {
        cout << digits[i % digits_count];
    }

    cout << '\n';

    return 0;
}
