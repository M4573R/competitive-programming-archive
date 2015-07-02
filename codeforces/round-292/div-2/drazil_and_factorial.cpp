#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const vector<string> factorization {
    "", "", "2", "3", "322", "5", "53", "7", "7222", "7332"
};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int digits;
    cin >> digits;

    string answer;

    for (unsigned int i {0}; i < digits; ++i)
    {
        char digit;
        cin >> digit;

        answer += factorization[digit - '0'];
    }

    sort(answer.begin(), answer.end(), greater<char>());

    cout << answer << '\n';

    return 0;
}
