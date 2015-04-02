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

    vector<unsigned int> counts(6);

    for (int number; cin >> number && number != -1; )
    {
        if (number < 50000)
        {
            ++counts[number / 10000];
        }
        else
        {
            ++counts[5];
        }
    }

    for (auto count : counts)
    {
        cout << count << '\n';
    }

    return 0;
}
