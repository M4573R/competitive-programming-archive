#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct Unit
{
    unsigned int rating;
    unsigned int count;

    Unit(unsigned int rating = 0,
         unsigned int count  = 0):
        rating(rating),
        count(count)
    { }
};

Unit merge(const Unit& left, const Unit& right)
{
    if (left.rating > right.rating)
    {
        return left;
    }
    else if (left.rating < right.rating)
    {
        return right;
    }
    else
    {
        return {left.rating, left.count + right.count};
    }
}

ostream& operator<<(ostream& out, const Unit& Unit)
{
    return out << Unit.rating << ' ' << Unit.count;
}

int main()
{
    use_io_optimizations();

    unsigned int episodes;
    unsigned int queries;

    cin >> episodes >> queries;

    vector<unsigned int> ratings(episodes);

    for (auto& rating : ratings)
    {
        cin >> rating;
    }

    vector<Unit> left(episodes + 1);

    for (unsigned int i {0}; i < episodes; ++i)
    {
        left[i + 1] = merge(left[i], Unit(ratings[i], 1));
    }

    vector<Unit> right(episodes + 2);

    for (unsigned int i {episodes}; i >= 1; --i)
    {
        right[i] = merge(right[i + 1], Unit(ratings[i - 1], 1));
    }

    for (unsigned int i {0}; i < queries; ++i)
    {
        unsigned int from;
        unsigned int to;

        cin >> from >> to;

        cout << merge(left[from - 1], right[to + 1]) << '\n';
    }

    return 0;
}
