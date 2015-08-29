#include <iostream>
#include <string>

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

    string salary;
    cin >> salary;

    for (string::size_type i {0}; i < salary.size() / 2; ++i)
    {
        if (salary[i] < salary[salary.size() - 1 - i])
        {
            string::size_type j {salary.size() - 1 - i - 1};

            while (salary[j] == '9')
            {
                salary[j--] = '0';
            }

            ++salary[j];
        }

        salary[salary.size() - 1 - i] = salary[i];
    }

    cout << salary << '\n';

    return 0;
}
