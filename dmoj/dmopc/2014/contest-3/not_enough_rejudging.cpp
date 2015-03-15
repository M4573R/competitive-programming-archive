#include <iostream>
#include <string>
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

    unsigned int statuses_count;
    cin >> statuses_count;

    unsigned int wrong_answers {0};
    vector<string> statuses(statuses_count);

    for (auto& status : statuses)
    {
        cin >> status;

        if (status == "WA")
        {
            ++wrong_answers;
        }
    }

    unsigned int accepted_wrong_answers = wrong_answers * 0.3;

    unsigned int wrong_answer   {0};
    unsigned int internal_error {0};

    for (const auto& status : statuses)
    {
        if (status == "AC")
        {
            cout << "AC";
        }
        else if (status == "WA")
        {
            cout << (wrong_answer < accepted_wrong_answers ? "AC" : "WA");
            ++wrong_answer;
        }
        else if (status == "TLE")
        {
            cout << "WA";
        }
        else if (status == "IR")
        {
            cout << (internal_error < 10 ? "AC" :
                     internal_error < 20 ? "WA" :
                                           "IR");
            ++internal_error;
        }

        cout << '\n';
    }

    return 0;
}
