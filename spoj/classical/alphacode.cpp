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

    for (string ciphertext; cin >> ciphertext && ciphertext != "0"; )
    {
        vector<unsigned long long> subtasks(ciphertext.size() + 1);

        subtasks[0] = 1;

        for (string::size_type i {1}; i <= ciphertext.size(); ++i)
        {
            if (ciphertext[i - 1] != '0')
            {
                subtasks[i] += subtasks[i - 1];

                if (i < ciphertext.size() &&
                    stoi(ciphertext.substr(i - 1, 2)) <= 26)
                {
                    subtasks[i + 1] += subtasks[i - 1];
                }
            }
        }

        cout << subtasks.back() << '\n';
    }

    return 0;
}
