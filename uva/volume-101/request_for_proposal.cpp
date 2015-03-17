#include <iostream>
#include <limits>
#include <string>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct Proposal
{
    string name;
    double price;
    unsigned int met_requirements;
};

istream& operator>>(istream& in, Proposal& proposal)
{
    getline(in, proposal.name);

    in >> proposal.price >> proposal.met_requirements;
    in.ignore();

    string requirement;

    for (unsigned int i {0}; i < proposal.met_requirements; ++i)
    {
        getline(in, requirement);
    }

    return in;
}

bool operator>(const Proposal& left, const Proposal& right)
{
    if (left.met_requirements > right.met_requirements)
    {
        return true;
    }

    if (left.met_requirements == right.met_requirements &&
        left.price < right.price)
    {
        return true;
    }

    return false;
}

int main()
{
    use_io_optimizations();

    unsigned int test {1};

    unsigned int requirements;
    unsigned int proposals;

    while (cin >> requirements >> proposals &&
           !(requirements == 0 && proposals == 0))
    {
        cin.ignore();

        string requirement;

        for (unsigned int i {0}; i < requirements; ++i)
        {
            getline(cin, requirement);
        }

        Proposal best;
        cin >> best;

        for (unsigned int i = 1; i < proposals; ++i)
        {
            Proposal current;
            cin >> current;

            if (current > best)
            {
                best = current;
            }
        }

        if (test > 1)
        {
            cout << '\n';
        }

        cout << "RFP #" << test++ << '\n'
             << best.name         << '\n';
    }

    return 0;
}
