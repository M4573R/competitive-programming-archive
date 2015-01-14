#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline unsigned int highest_rank(const vector<unsigned int>& rankings)
{
    return *max_element(rankings.begin(), rankings.end());
}

unsigned int lowest_rank(const vector<unsigned int>& rankings)
{
    unsigned int lowest {0};

    for (vector<unsigned int>::size_type i {1}; i < rankings.size(); ++i)
    {
        if (rankings[i] != 0 &&
            (rankings[lowest] == 0 || rankings[lowest] > rankings[i]))
        {
            lowest = i;
        }
    }

    return rankings[lowest];
}

vector<unsigned int>
calculate_rankings(const vector<vector<unsigned int>>& ballots,
                   const vector<unsigned int>& ballot_indices,
                   unsigned int candidates)
{
    vector<unsigned int> rankings(candidates);

    for (unsigned int i {0}; i < ballots.size(); ++i)
    {
        ++rankings[ballots[i][ballot_indices[i]]];
    }

    return rankings;
}

vector<string> winners(const vector<string>& candidates,
                       const vector<unsigned int>& rankings,
                       unsigned int ballots_count)
{
    for (vector<unsigned int>::size_type i {0}; i < rankings.size(); ++i)
    {
        if (rankings[i] > ballots_count / 2)
        {
            return {candidates[i]};
        }
    }

    unsigned int max_rank {highest_rank(rankings)};
    unsigned int min_rank {lowest_rank(rankings)};

    if (min_rank == max_rank)
    {
        vector<string> tied;

        for (vector<unsigned int>::size_type i {0}; i < rankings.size(); ++i)
        {
            if (rankings[i] == min_rank)
            {
                tied.push_back(candidates[i]);
            }
        }

        return tied;
    }

    return {};
}

set<unsigned int> eliminated(const vector<unsigned int>& rankings)
{
    set<unsigned int> losers;

    unsigned int min_rank {lowest_rank(rankings)};

    for (vector<unsigned int>::size_type i {1}; i < rankings.size(); ++i)
    {
        if (rankings[i] == min_rank)
        {
            losers.insert(i);
        }
    }

    return losers;
}

vector<unsigned int>
update_ballots(const vector<vector<unsigned int>>& ballots,
               const vector<unsigned int>& ballot_indices,
               const set<unsigned int>& losers)
{
    vector<unsigned int> updated_indices {ballot_indices};

    for (vector<vector<unsigned int>>::size_type i {0}; i < ballots.size(); ++i)
    {
        while (losers.find(ballots[i][updated_indices[i]]) != losers.end())
        {
            ++updated_indices[i];
        }
    }

    return updated_indices;
}

vector<string> election_finalists(const vector<string>& candidates,
                                  const vector<vector<unsigned int>>& ballots)
{
    vector<unsigned int> ballot_indices(ballots.size());
    vector<string>       finalists;

    while (finalists.empty())
    {
        vector<unsigned int> rankings {calculate_rankings(ballots,
                                                          ballot_indices,
                                                          candidates.size())};

        finalists      = winners(candidates,
                                 rankings,
                                 ballots.size());

        ballot_indices = update_ballots(ballots,
                                        ballot_indices,
                                        eliminated(rankings));
    }

    return finalists;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        unsigned int candidates_count;
        cin >> candidates_count;
        cin.get();

        vector<string> candidates(candidates_count + 1);

        for (unsigned int j {1}; j <= candidates_count; ++j)
        {
            getline(cin, candidates[j]);
        }

        vector<vector<unsigned int>> ballots;

        string line;
        getline(cin, line);

        while (!line.empty())
        {
            istringstream        ballot_input{line};
            vector<unsigned int> ballot(candidates_count);

            for (auto candidate_number = ballot.begin();
                 ballot_input >> *candidate_number;
                 ++candidate_number)
            { }

            ballots.push_back(ballot);
            getline(cin, line);
        }

        for (const auto& winner : election_finalists(candidates, ballots))
        {
            cout << winner << '\n';
        }

        if (i < test_cases - 1)
        {
            cout << '\n';
        }
    }

    return 0;
}
