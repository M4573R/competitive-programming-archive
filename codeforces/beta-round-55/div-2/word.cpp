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

    string word;
    cin >> word;

    unsigned int lower = count_if(word.cbegin(), word.cend(), ::islower);
    unsigned int upper = count_if(word.cbegin(), word.cend(), ::isupper);

    transform(word.begin(),
              word.end(),
              word.begin(),
              lower < upper ? ::toupper : ::tolower);

    cout << word << '\n';

    return 0;
}
