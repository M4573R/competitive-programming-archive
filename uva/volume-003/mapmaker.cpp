#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct Array
{
    unsigned int base_address;
    unsigned int dimensions;
    unsigned int element_size;

    vector<int> lower;
    vector<int> upper;
    vector<int> constants;

    void calculate_constants()
    {
        constants.resize(dimensions + 1);
        constants.back() = element_size;

        for (unsigned int i {dimensions - 1}; i > 0; --i)
        {
            constants[i] = constants[i + 1] * (upper[i] - lower[i] + 1);
        }

        constants.front() = base_address;

        for (unsigned int i {1}; i <= dimensions; ++i)
        {
            constants.front() -= constants[i] * lower[i - 1];
        }
    }
};

istream& operator>>(istream& in, Array& array)
{
    in >> array.base_address
       >> array.element_size
       >> array.dimensions;

    array.lower.resize(array.dimensions);
    array.upper.resize(array.dimensions);

    for (unsigned int i {0}; i < array.dimensions; ++i)
    {
        cin >> array.lower[i] >> array.upper[i];
    }

    array.calculate_constants();

    return in;
}

struct Reference
{
    string array;
    vector<int> indices;
};

istream& operator>>(istream& in, Reference& reference)
{
    in >> reference.array;

    string rest;
    getline(in, rest);

    istringstream indices {rest};

    for (int index; indices >> index; )
    {
        reference.indices.push_back(index);
    }
}

void read_input(map<string, Array>& arrays, vector<Reference>& references)
{
    unsigned int arrays_count;
    unsigned int references_count;

    cin >> arrays_count >> references_count;

    for (unsigned int i {0}; i < arrays_count; ++i)
    {
        string name;
        Array array;

        cin >> name >> array;

        arrays[name] = array;
    }

    references.resize(references_count);

    for (auto& reference : references)
    {
        cin >> reference;
    }
}

int main()
{
    use_io_optimizations();

    map<string, Array> arrays;
    vector<Reference> references;

    read_input(arrays, references);

    for (const auto& reference : references)
    {
        auto array            = arrays[reference.array];
        auto physical_address = array.constants.front();

        cout << reference.array << '[';

        for (unsigned int i {0}; i < array.dimensions; ++i)
        {
            if (i != 0)
            {
                cout << ", ";
            }

            cout << reference.indices[i];

            physical_address += array.constants[i + 1] * reference.indices[i];
        }

        cout << "] = " << physical_address << '\n';
    }

    return 0;
}
