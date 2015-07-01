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

    unsigned int size;
    cin >> size;

    vector<int> numbers(size);

    for (auto& number : numbers)
    {
        cin >> number;
    }

    auto minimum = min_element(numbers.cbegin(), numbers.cend());

    cout << "Menor valor: " << *minimum                   << '\n'
         << "Posicao: "     << minimum - numbers.cbegin() << '\n';

    return 0;
}
