#include <iostream>
#include <set>
#include <string>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void send_cookie(multiset<unsigned int>& diameters,
                 multiset<unsigned int>::iterator& median)
{
    auto new_median = median;

    if (diameters.size() % 2)
    {
        ++new_median;
    }
    else
    {
        --new_median;
    }

    diameters.erase(median);
    median = new_median;
}

void add_cookie(multiset<unsigned int>& diameters,
                multiset<unsigned int>::iterator& median,
                unsigned int diameter)
{
    diameters.insert(diameter);

    if (diameters.size() == 1)
    {
        median = diameters.begin();
    }
    else if (diameters.size() % 2)
    {
        if (diameter < *median)
        {
            --median;
        }
    }
    else
    {
        if (diameter >= *median)
        {
            ++median;
        }
    }
}

int main()
{
    use_io_optimizations();

    multiset<unsigned int> diameters;
    multiset<unsigned int>::iterator median;

    for (string operation; cin >> operation; )
    {
        if (operation == "#")
        {
            cout << *median << '\n';

            send_cookie(diameters, median);
        }
        else
        {
            add_cookie(diameters, median, stoi(operation));
        }
    }

    return 0;
}
