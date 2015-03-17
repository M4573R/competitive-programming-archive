#include <iomanip>
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
    cin.ignore();

    for (unsigned int test {1}; test <= test_cases; ++test)
    {
        string commands;
        getline(cin, commands);

        unsigned int pointer {0};
        vector<unsigned int> memory(100);

        for (auto command : commands)
        {
            switch (command)
            {
            case '<':
                pointer = (pointer + 99) % 100;
                break;

            case '>':
                pointer = (pointer + 1) % 100;
                break;

            case '+':
                memory[pointer] = (memory[pointer] + 1) % 256;
                break;

            case '-':
                memory[pointer] = (memory[pointer] + 255) % 256;
                break;
            }
        }

        cout << "Case " << dec << test << ": ";

        for (unsigned int i {0}; i < 100; ++i)
        {
            cout << hex << uppercase << setw(2) << setfill('0') << memory[i];
            cout << (i < 99 ? ' ' : '\n');
        }
    }

    return 0;
}
