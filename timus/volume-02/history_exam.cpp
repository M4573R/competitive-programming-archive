#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int professor_dates_count;
    cin >> professor_dates_count;

    vector<unsigned int> professor_dates(professor_dates_count);

    for (auto& date : professor_dates)
    {
        cin >> date;
    }

    unsigned int student_dates_count;
    cin >> student_dates_count;

    unsigned int matched_dates {0};

    for (unsigned int i {0}; i < student_dates_count; ++i)
    {
        unsigned int student_date;
        cin >> student_date;

        if (binary_search(professor_dates.cbegin(),
                          professor_dates.cend(),
                          student_date))
        {
            ++matched_dates;
        }
    }

    cout << matched_dates << '\n';

    return 0;
}
