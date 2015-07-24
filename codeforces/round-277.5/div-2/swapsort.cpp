#include <iostream>
#include <utility>
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

    vector<int> elements(size);

    for (auto& element : elements)
    {
        cin >> element;
    }

    cout << size << '\n';

    for (unsigned int i {0}; i < size; ++i)
    {
        unsigned int min {i};

        for (unsigned int j {i + 1}; j < size; ++j)
        {
            if (elements[j] < elements[min])
            {
                min = j;
            }
        }

        swap(elements[i], elements[min]);
        cout << i << ' ' << min << '\n';
    }

    return 0;
}
