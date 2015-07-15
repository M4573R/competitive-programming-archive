#include <iostream>
#include <vector>

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

    unsigned int students;
    cin >> students;

    if (students <= 2)
    {
        cout << "1\n1\n";
    }
    else if (students == 3)
    {
        cout << "2\n1 3\n";
    }
    else
    {
        cout << students << '\n';

        for (unsigned int i {2}; i <= students; i += 2)
        {
            cout << i << ' ';
        }

        for (unsigned int i {1}; i <= students; i += 2)
        {
            cout << i << " \n"[i == students];
        }
    }

    return 0;
}
