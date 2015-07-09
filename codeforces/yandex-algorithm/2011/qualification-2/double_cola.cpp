#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr unsigned int people {5};

const vector<string> names {
    "Sheldon", "Leonard", "Penny", "Rajesh", "Howard"
};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int position;
    cin >> position;

    unsigned int iteration {1};

    for (; position > iteration * people; iteration *= 2)
    {
        position -= iteration * people;
    }

    cout << names[(position + iteration - 1) / iteration - 1] << '\n';

    return 0;
}
