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

void initialize(vector<unsigned int>& initial,
                vector<unsigned int>& sorted)
{
    unsigned int size;
    cin >> size;

    initial.resize(size);

    for (auto& element : initial)
    {
        cin >> element;
    }

    sorted = initial;
    sort(sorted.begin(), sorted.end());
}

void find_segment(const vector<unsigned int>& initial,
                  const vector<unsigned int>& sorted,
                  unsigned int& left,
                  unsigned int& right)
{
    left  = initial.size() - 1;
    right = 0;

    for (unsigned int i {0}; i < initial.size(); ++i)
    {
        if (initial[i] != sorted[i])
        {
            left  = min(left, i);
            right = max(right, i);
        }
    }
}

int main()
{
    use_io_optimizations();

    vector<unsigned int> initial;
    vector<unsigned int> sorted;

    initialize(initial, sorted);

    unsigned int left;
    unsigned int right;

    find_segment(initial, sorted, left, right);

    if (left > right)
    {
        cout << "yes\n" << "1 1\n";
    }
    else
    {
        reverse(initial.begin() + left, initial.begin() + right + 1);

        for (unsigned int i {0}; i < initial.size(); ++i)
        {
            if (initial[i] != sorted[i])
            {
                cout << "no\n";
                return 0;
            }
        }

        cout << "yes\n" << left + 1 << ' ' << right + 1 << '\n';
    }

    return 0;
}

