#include <cstdlib>
#include <iostream>
#include <string>
#include <map>

using namespace std;

const map<string, int> name_to_case {
    {"Alice",   1}, {"Ariel",  1}, {"Aurora", 1},
    {"Phil",    1}, {"Peter",  1}, {"Olaf",   1},
    {"Phoebus", 1}, {"Ralph",  1}, {"Robin",  1},
    {"Bambi",   2}, {"Belle",  2}, {"Bolt",   2},
    {"Mulan",   2}, {"Mowgli", 2}, {"Mickey", 2},
    {"Silver",  2}, {"Simba",  2}, {"Stitch", 2},
    {"Dumbo",   3}, {"Genie",  3}, {"Jiminy", 3},
    {"Kuzko",   3}, {"Kida",   3}, {"Kenai",  3},
    {"Tarzan",  3}, {"Tiana",  3}, {"Winnie", 3}
};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int letters;
    cin >> letters;

    int current_case   {1};
    unsigned int steps {0};

    for (unsigned int i {0}; i < letters; ++i)
    {
        string receiver;
        cin >> receiver;

        steps        += abs(current_case - name_to_case.at(receiver));
        current_case  = name_to_case.at(receiver);
    }

    cout << steps << '\n';

    return 0;
}
