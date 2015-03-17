#include <iostream>
#include <set>

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

    unsigned int courses;
    unsigned int categories;

    while (cin >> courses && courses != 0 && cin >> categories)
    {
        set<unsigned int> chosen;

        for (unsigned int i {0}; i < courses; ++i)
        {
            unsigned int course;
            cin >> course;

            chosen.insert(course);
        }

        bool will_graduate {true};

        for (unsigned int i {0}; i < categories; ++i)
        {
            unsigned int total;
            unsigned int required;

            cin >> total >> required;

            unsigned int matches {0};

            for (unsigned int j {0}; j < total; ++j)
            {
                unsigned int course;
                cin >> course;

                matches += chosen.count(course);
            }

            if (matches < required)
            {
                will_graduate = false;
            }
        }

        cout << (will_graduate ? "yes" : "no") << '\n';
    }

    return 0;
}
