#include <iostream>
#include <set>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void read_input(unsigned int& marks_count,
                unsigned int& ruler_length,
                unsigned int& girls_norm,
                unsigned int& boys_norm,
                set<unsigned int>& marks)
{
    cin >> marks_count
        >> ruler_length
        >> girls_norm
        >> boys_norm;

    for (unsigned int i {0}; i < marks_count; ++i)
    {
        unsigned int distance_from_origin;
        cin >> distance_from_origin;

        marks.insert(distance_from_origin);
    }
}

void write_output(const vector<unsigned int>& added_marks)
{
    cout << added_marks.size() << '\n';

    for (auto mark = added_marks.cbegin(); mark != added_marks.cend(); ++mark)
    {
        cout << *mark;

        if (mark < added_marks.cend() - 1)
        {
            cout << ' ';
        }
    }

    if (!added_marks.empty())
    {
        cout << '\n';
    }
}

int can_measure(const set<unsigned int>& marks, unsigned int measurement)
{
    for (unsigned int mark : marks)
    {
        if (marks.count(mark + measurement))
        {
            return mark;
        }
    }

    return -1;
}

vector<unsigned int> minimum_added_marks(const set<unsigned int>& marks,
                                         unsigned int ruler_length,
                                         unsigned int girls_norm,
                                         unsigned int boys_norm)
{
    vector<unsigned int> added_marks;

    int girls_mark          {can_measure(marks, girls_norm)};
    int boys_mark           {can_measure(marks, boys_norm)};
    int girls_and_boys_mark {can_measure(marks, girls_norm + boys_norm)};

    if (girls_mark >= 0 || boys_mark >= 0)
    {
        if (girls_mark < 0)
        {
            added_marks.push_back(girls_norm);
        }

        if (boys_mark < 0)
        {
            added_marks.push_back(boys_norm);
        }
    }
    else if (girls_and_boys_mark >= 0)
    {
        added_marks.push_back(girls_and_boys_mark + girls_norm);
    }
    else
    {
        for (unsigned int mark : marks)
        {
            if (mark >= girls_norm || mark <= ruler_length - boys_norm)
            {
                if (marks.count(mark + (boys_norm - girls_norm)))
                {
                    if (mark >= girls_norm)
                    {
                        added_marks.push_back(mark - girls_norm);
                    }
                    else
                    {
                        added_marks.push_back(mark + boys_norm);
                    }

                    break;
                }
            }
        }

        if (added_marks.empty())
        {
            added_marks.push_back(girls_norm);
            added_marks.push_back(boys_norm);
        }
    }

    return added_marks;
}

int main()
{
    use_io_optimizations();

    unsigned int marks_count;
    unsigned int ruler_length;

    unsigned int girls_norm;
    unsigned int boys_norm;

    set<unsigned int> marks;

    read_input(marks_count,
               ruler_length,
               girls_norm,
               boys_norm,
               marks);

    vector<unsigned int> added_marks {minimum_added_marks(marks,
                                                          ruler_length,
                                                          girls_norm,
                                                          boys_norm)};

    write_output(added_marks);

    return 0;
}
