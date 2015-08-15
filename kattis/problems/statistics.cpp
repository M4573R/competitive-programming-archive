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

    for (unsigned int size, test {1}; cin >> size; ++test)
    {
        vector<int> sample(size);

        for (auto& element : sample)
        {
            cin >> element;
        }

        auto minimum = *min_element(sample.cbegin(), sample.cend());
        auto maximum = *max_element(sample.cbegin(), sample.cend());

        cout << "Case " << test << ": "
             << minimum << ' '
             << maximum << ' '
             << maximum - minimum << '\n';
    }

    return 0;
}
