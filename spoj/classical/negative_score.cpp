#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef pair<unsigned int, unsigned int> Query;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

class StaticRmq
{
public:
    StaticRmq(const vector<int>& array):
        ranges(array.size(), vector<int>(log2(array.size()) + 1))
    {
        typedef vector<int>::size_type index;

        index n = array.size();

        for (index i = 0; i < n; ++i)
        {
            ranges[i][0] = array[i];
        }

        for (index j = 1; (1 << j) <= n; ++j)
        {
            for (index i = 0; i + (1 << j) - 1 < n; ++i)
            {
                ranges[i][j] = min(ranges[i][j - 1],
                                   ranges[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int get(unsigned int left, unsigned int right) const
    {
        unsigned int k = log2(right - left + 1);

        return min(ranges[left][k], ranges[right - (1 << k) + 1][k]);
    }

private:
    vector< vector<int> > ranges;
};

void read_input(unsigned int&  evaluations_count,
                vector<int>&   evaluations,
                unsigned int&  queries_count,
                vector<Query>& queries)
{
    cin >> evaluations_count;
    cin >> queries_count;

    evaluations = vector<int>(evaluations_count);

    for (unsigned int i = 0; i < evaluations_count; ++i)
    {
        cin >> evaluations[i];
    }

    queries = vector<Query>(queries_count);

    for (unsigned int i = 0; i < queries_count; ++i)
    {
        cin >> queries[i].first >> queries[i].second;
    }
}

void write_output(unsigned int test_case,
                  const StaticRmq& rmq,
                  const vector<Query>& queries)
{
    cout << "Scenario #" << test_case + 1 << ":\n\n";

    for (vector<Query>::const_iterator query = queries.begin();
         query != queries.end();
         ++query)
    {
        cout << rmq.get(query->first - 1, query->second - 1) << "\n\n";
    }
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i = 0; i < test_cases; ++i)
    {
        unsigned int evaluations_count;
        vector<int>  evaluations;

        unsigned int  queries_count;
        vector<Query> queries;

        read_input(evaluations_count, evaluations, queries_count, queries);

        StaticRmq rmq(evaluations);

        write_output(i, rmq, queries);
    }

    return 0;
}
