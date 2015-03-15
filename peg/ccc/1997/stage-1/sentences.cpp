#include <iostream>
#include <string>
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

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int subjects_count;
        unsigned int verbs_count;
        unsigned int objects_count;

        cin >> subjects_count
            >> verbs_count
            >> objects_count;

        cin.ignore();

        vector<string> subjects(subjects_count);

        for (auto& subject : subjects)
        {
            getline(cin, subject);
        }

        vector<string> verbs(verbs_count);

        for (auto& verb : verbs)
        {
            getline(cin, verb);
        }

        vector<string> objects(objects_count);

        for (auto& object : objects)
        {
            getline(cin, object);
        }

        for (const auto& subject : subjects)
        {
            for (const auto& verb : verbs)
            {
                for (const auto& object : objects)
                {
                    cout << subject << ' ' << verb << ' ' << object << ".\n";
                }
            }
        }
    }

    return 0;
}
