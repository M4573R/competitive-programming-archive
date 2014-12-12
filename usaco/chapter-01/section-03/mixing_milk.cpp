/*
    ID:   gsshopo1
    PROG: milk
    LANG: C++11
*/

#include <algorithm>
#include <fstream>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    ifstream fin  {"milk.in"};
    ofstream fout {"milk.out"};

    unsigned int needed_milk;
    fin >> needed_milk;

    unsigned int farmers;
    fin >> farmers;

    vector<pair<unsigned int, unsigned int>> offers(farmers);

    for (auto& offer : offers)
    {
        fin >> offer.first >> offer.second;
    }

    sort(offers.begin(), offers.end());

    unsigned long long spent_money {0};

    for (unsigned int i {0}; i < farmers && needed_milk > 0; ++i)
    {
        unsigned int bought {min(needed_milk, offers[i].second)};

        spent_money += static_cast<unsigned long long>(offers[i].first) * bought;
        needed_milk -= bought;
    }

    fout << spent_money << '\n';

    return 0;
}
