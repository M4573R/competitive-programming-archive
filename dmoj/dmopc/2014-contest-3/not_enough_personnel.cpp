#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct Employee
{
    string name;
    unsigned int skill_level;
};

bool operator<(const Employee& left, const Employee& right)
{
    return left.skill_level < right.skill_level;
}

int main()
{
    use_io_optimizations();

    unsigned int existing_employees_count;
    cin >> existing_employees_count;

    vector<Employee> existing_employees(existing_employees_count);

    for (auto& employee : existing_employees)
    {
        cin >> employee.name >> employee.skill_level;
    }

    stable_sort(existing_employees.begin(), existing_employees.end());

    unsigned int new_employees;
    cin >> new_employees;

    for (unsigned int i {0}; i < new_employees; ++i)
    {
        unsigned int skill_level;
        unsigned int adaptability_factor;

        cin >> skill_level >> adaptability_factor;

        string teacher;

        for (const auto& employee : existing_employees)
        {
            if (employee.skill_level >= skill_level &&
                employee.skill_level <= skill_level + adaptability_factor)
            {
                teacher = employee.name;
                break;
            }
        }

        cout << (teacher.empty() ? "No suitable teacher!" : teacher) << '\n';
    }

    return 0;
}
