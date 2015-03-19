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

    unsigned int votes_count;
    cin >> votes_count;

    string votes;
    cin >> votes;

    auto a_votes = count(votes.cbegin(), votes.cend(), 'A');
    auto b_votes = count(votes.cbegin(), votes.cend(), 'B');

    cout << (a_votes > b_votes ? "A":
             b_votes > a_votes ? "B":
                                 "Tie") << '\n';

    return 0;
}
