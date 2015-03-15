#include <iomanip>
#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    cout << fixed << setprecision(3);

    unsigned int marks {0};

    unsigned int initial_students;
    cin >> initial_students;

    for (unsigned int i {0}; i < initial_students; ++i)
    {
        unsigned int mark;
        cin >> mark;

        marks += mark;
    }

    unsigned int transfering_students;
    cin >> transfering_students;

    for (unsigned int i {1}; i <= transfering_students; ++i)
    {
        unsigned int mark;
        cin >> mark;

        marks += mark;

        cout << static_cast<double>(marks) / (initial_students + i) << '\n';
    }

    return 0;
}
