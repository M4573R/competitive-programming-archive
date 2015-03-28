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

    unsigned int questions;
    cin >> questions;

    vector<char> answers(questions);

    for (auto& answer : answers)
    {
        cin >> answer;
    }

    unsigned int correct_answers {0};

    for (unsigned int i {0}; i < questions; ++i)
    {
        char answer_key;
        cin >> answer_key;

        if (answers[i] == answer_key)
        {
            ++correct_answers;
        }
    }

    cout << correct_answers << '\n';

    return 0;
}
