#include <iostream>
#include <map>
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
    int base_address;
    int dimensions;
    int element_size;

    vector<int> lower_bounds;
    vector<int> upper_bounds;
    vector<int> constants;

    void calculate_constants();
};

void Array::calculate_constants()
{
    constants.resize(dimensions + 1);
    constants.back() = element_size;

    for (int i {dimensions - 1}; i > 0; --i)
    {
        constants[i] = constants[i + 1] * (upper_bounds[i] - lower_bounds[i] + 1);
    }

    constants.front() = base_address;

    for (int i {1}; i <= dimensions; ++i)
    {
        constants.front() -= constants[i] * lower_bounds[i - 1];
    }
}

istream& operator>>(istream& in, Array& array)
{
    in >> array.base_address >> array.element_size >> array.dimensions;

    array.lower_bounds.resize(array.dimensions);
    array.upper_bounds.resize(array.dimensions);

    for (int i {0}; i < array.dimensions; ++i)
    {
        cin >> array.lower_bounds[i] >> array.upper_bounds[i];
    }

    array.calculate_constants();
}

int main()
{
    use_io_optimizations();

    int arrays_count;
    int references;

    cin >> arrays_count >> references;

    map<string, int> positions;
    vector<Array> arrays(arrays_count);

    for (int i {0}; i < arrays_count; ++i)
    {
        string name;

        cin >> name;
        cin >> arrays[i];

        positions[name] = i;
    }

    for (int i {0}; i < references; ++i)
    {
        string name;
        cin >> name;

        int position         {positions[name]};
        int physical_address {arrays[position].constants.front()};

        cout << name << '[';

        for (int j {0}; j < arrays[position].dimensions; ++j)
        {
            if (j != 0)
            {
                cout << ", ";
            }

            int index;
            cin >> index;

            cout << index;

            physical_address += arrays[position].constants[j + 1] * index;
        }

        cout << "] = " << physical_address << '\n';
    }

    return 0;
}
