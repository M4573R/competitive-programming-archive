/*
    ID:   gsshopo1
    PROG: combo
    LANG: C++11
*/

#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;

inline
bool is_close(int first, int second, int size)
{
    return abs(first - second) <= 2 || size - abs(first - second) <= 2;
}

inline
bool is_key(int first, int second, int third, int size, const vector<int>& key)
{
    return (is_close(first,  key[0], size) &&
            is_close(second, key[1], size) &&
            is_close(third,  key[2], size));
}

int main()
{
    ifstream fin  {"combo.in"};
    ofstream fout {"combo.out"};

    int size;
    fin >> size;

    vector<int> farmer_key(3);
    vector<int> master_key(3);

    for (auto& number : farmer_key)
    {
        fin >> number;
    }

    for (auto& number : master_key)
    {
        fin >> number;
    }

    unsigned int keys {0};

    for (int first {1}; first <= size; ++first)
    {
        for (int second {1}; second <= size; ++second)
        {
            for (int third {1}; third <= size; ++third)
            {
                if (is_key(first, second, third, size, farmer_key) ||
                    is_key(first, second, third, size, master_key))
                {
                    ++keys;
                }
            }
        }
    }

    fout << keys << '\n';

    return 0;
}
