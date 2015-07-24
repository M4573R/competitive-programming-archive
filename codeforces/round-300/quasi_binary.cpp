#include <algorithm>
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

    string number;
    cin >> number;

    unsigned int summands = *max_element(number.cbegin(), number.cend()) - '0';

    cout << summands << '\n';

    for (unsigned int i {0}; i < summands; ++i)
    {
        string summand;

        for (auto digit : number)
        {
            summand += (i < digit - '0' ? '1' : '0');
        }

        cout << stoi(summand) << " \n"[i + 1 == summands];
    }

    return 0;
}
