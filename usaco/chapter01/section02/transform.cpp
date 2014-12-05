/*
    ID:   gsshopo1
    PROG: transform
    LANG: C++11
*/

#include <fstream>
#include <vector>

using namespace std;

using Row            = vector<char>;
using Pattern        = vector<Row>;
using Transformation = bool (*)(const Pattern&, const Pattern&);

Pattern rotate(const Pattern& pattern)
{
    auto size = pattern.size();
    Pattern rotated(size, Row(size));

    for (Pattern::size_type i {0}; i < size; ++i)
    {
        for (Pattern::size_type j {0}; j < size; ++j)
        {
            rotated[j][size - 1 - i] = pattern[i][j];
        }
    }

    return rotated;
}

Pattern reflect(const Pattern& pattern)
{
    auto size = pattern.size();
    Pattern reflected(size, Row(size));

    for (Pattern::size_type i {0}; i < size; ++i)
    {
        for (Pattern::size_type j {0}; j < size; ++j)
        {
            reflected[i][size - 1 - j] = pattern[i][j];
        }
    }

    return reflected;
}

inline bool is_rotated_90(const Pattern& original, const Pattern& transformed)
{
    return transformed == rotate(original);
}

inline bool is_rotated_180(const Pattern& original, const Pattern& transformed)
{
   return transformed == rotate(rotate(original));
}

inline bool is_rotated_270(const Pattern& original, const Pattern& transformed)
{
    return transformed == rotate(rotate(rotate(original)));
}

inline bool is_reflected(const Pattern& original, const Pattern& transformed)
{
    return transformed == reflect(original);
}

inline bool is_combined(const Pattern& original, const Pattern& transformed)
{
    return (transformed == rotate(reflect(original))         ||
            transformed == rotate(rotate(reflect(original))) ||
            transformed == rotate(rotate(rotate(reflect(original)))));
}

inline bool is_unchanged(const Pattern& original, const Pattern& transformed)
{
    return original == transformed;
}

const vector<Transformation> transformations {
    is_rotated_90,
    is_rotated_180,
    is_rotated_270,
    is_reflected,
    is_combined,
    is_unchanged
};

Pattern initialize_pattern(unsigned int size, ifstream& fin)
{
    Pattern pattern(size, Row(size));

    for (auto& row : pattern)
    {
        for (auto& element : row)
        {
            fin >> element;
        }
    }

    return pattern;
}

int main()
{
    ifstream fin  {"transform.in"};
    ofstream fout {"transform.out"};

    unsigned int size;
    fin >> size;

    Pattern original    {initialize_pattern(size, fin)};
    Pattern transformed {initialize_pattern(size, fin)};

    for (vector<Transformation>::size_type i {0}; i < transformations.size(); ++i)
    {
        if (transformations[i](original, transformed))
        {
            fout << i + 1 << '\n';
            return 0;
        }
    }

    fout << transformations.size() + 1 << '\n';

    return 0;
}
