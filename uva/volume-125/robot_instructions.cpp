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

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        int position {0};

        unsigned int instructions;
        cin >> instructions;

        vector<int> moves(instructions);

        for (auto& move : moves)
        {
            string type;
            cin >> type;

            if (type == "SAME")
            {
                string leftover;
                cin >> leftover;

                unsigned int index;
                cin >> index;

                move = moves[index - 1];
            }
            else
            {
                move = (type == "LEFT" ? -1 : 1);
            }

            position += move;
        }

        cout << position << '\n';
    }

    return 0;
}
