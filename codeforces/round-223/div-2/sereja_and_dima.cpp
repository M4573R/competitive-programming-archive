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

    unsigned int cards;
    cin >> cards;

    vector<unsigned int> numbers(cards);

    for (auto& number : numbers)
    {
        cin >> number;
    }

    vector<unsigned int> points(2);

    for (unsigned int player {0}, i {0}, j {cards - 1}; i <= j; ++player)
    {
        if (numbers[i] >= numbers[j])
        {
            points[player % 2] += numbers[i++];
        }
        else
        {
            points[player % 2] += numbers[j--];
        }
    }

    cout << points[0] << ' ' << points[1] << '\n';

    return 0;
}
